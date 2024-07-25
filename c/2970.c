
/*
 2970. 统计移除递增子数组的数目 I
 
 给你一个下标从 0 开始的 正 整数数组 nums 。

 如果 nums 的一个子数组满足：移除这个子数组后剩余元素 严格递增 ，那么我们称这个子数组为 移除递增 子数组。比方说，[5, 3, 4, 6, 7] 中的 [3, 4] 是一个移除递增子数组，因为移除该子数组后，[5, 3, 4, 6, 7] 变为 [5, 6, 7] ，是严格递增的。

 请你返回 nums 中 移除递增 子数组的总数目。

 注意 ，剩余元素为空的数组也视为是递增的。

 子数组 指的是一个数组中一段连续的元素序列。

 */

// 暴力法
int incremovableSubarrayCount(int* nums, int numsSize) {
    
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i; j < numsSize; ++j) {
            if (j+1 < numsSize && i-1 >= 0) {
                if (nums[j+1] <= nums[i-1]) {
                    // 不是递增
                    continue;
                }
            }
            
            int needContinue = 0
            for (int k = 1; k < i; ++k) {
                if (nums[k] <= nums[k-1]) {
                    // 不是递增
                    needContinue = 1;
                    break;
                }
            }
            if (needContinue == 1) {
                continue;
            }
            for (int k = j+2; k < numsSize; ++k) {
                if (nums[k] <= nums[k-1]) {
                    // 不是递增
                    needContinue = 1;
                    break;
                }
            }
            if (needContinue == 1) {
                continue;
            }
            count += 1;
        }
    }
    
    return count;
}

/// 双指针法
/// 子数组用sub[l, r]表示
/// 如果去掉子数组sub[l, r]后，剩余数组是严格递增的，那么有sub[0, l-1]，sub[r+1, n]都是递增数组，且nums[l-1] < nums[r+1]
/// 那么需要找到，从左开始第一个非递增的位置L和从右开始第一个非递增位置R，可以看出必须有l<=L和r>=R，剩余的数组才有可能是递增的
int incremovableSubarrayCount(int* nums, int numsSize) {
    int res = 0;
    int l = 1;
    // 找出位置L
    while (l < numsSize && nums[l - 1] < nums[l]) {
        l++;
    }
    res += l + (l < numsSize);
    for (int r = numsSize - 2; r >= 0; r--) {
        while (l > 0 && nums[l - 1] >= nums[r + 1]) {
            // 找出左数组中最大值比右数组最小值小的位置
            l--;
        }
        res += l + (l <= r);
        
        if (nums[r] >= nums[r + 1]) {
            // 找出位置R，结束循环，因为剩下的都不可能构成递增数组了
            break;
        }
    }
    return res;

}
