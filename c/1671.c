/*
 1671. 得到山形数组的最少删除次数
 我们定义 arr 是 山形数组 当且仅当它满足：

 arr.length >= 3
 存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
 arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。

简单来说就是，通过删除数组的元素，让数组变成一个先递增后递减的数组，然后找出符合条件的最长数组
 */

// 找出最接近target值的位置
int binarySearch(const int *seq, int seqSize, int target) {
    int low = 0, high = seqSize;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (seq[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// 计算出数组中每个位置的最长严格递增数组长度
int *getLISArray(const int* nums, int numsSize) {
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }
    // 维护一个严格递增数组
    int seq[numsSize], pos = 0;
    for (int i = 0; i < numsSize; ++i) {
        int index = binarySearch(seq, pos, nums[i]);
        if (index == pos) {
            seq[pos++] = nums[i];
            dp[i] = pos;
        } else {
            seq[index] = nums[i];
            dp[i] = index + 1;
        }
    }
    return dp;
}

void reverse(int *nums, int numsSize) {
    for (int i = 0, j = numsSize - 1; i < j; i++, j--) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

int minimumMountainRemovals(int* nums, int numsSize) {
    int n = numsSize;
    int *pre = getLISArray(nums, numsSize);
    reverse(nums, numsSize);
    int *suf = getLISArray(nums, numsSize);
    reverse(suf, numsSize);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (pre[i] > 1 && suf[i] > 1) {
            ans = fmax(ans, pre[i] + suf[i] - 1);
        }
    }
    free(pre);
    free(suf);
    return n - ans;
}

