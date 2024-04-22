/*
 给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。

 一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 。

 请你返回 好 子数组的最大可能 分数 。
 */
int maximumScore(int* nums, int numsSize, int k) {
    // 暴力法 O(n^2)，会超时
//    int leftMinNum = nums[k];
//    int left = k;
//    int right = k;
//    
//    int maxScore = 0;
//    
//    while(left >= 0) {
//        if (nums[left] < leftMinNum) {
//            leftMinNum = nums[left];
//        }
//        int minNum = leftMinNum;
//        right = k;
//        while (right < numsSize) {
//            if (nums[right] < minNum) {
//                minNum = nums[right];
//            }
//            int tmpScore = (right-left+1)*minNum;
//            if (tmpScore > maxScore) {
//                maxScore = tmpScore;
//            }
//            ++right;
//            
//        }
//        
//        --left;
//    }
//    
//    return maxScore;
    
    int left = k - 1, right = k + 1;
        int ans = 0;
        for (int i = nums[k];;) {
            while (left >= 0 && nums[left] >= i) {
                --left;
            }
            while (right < numsSize && nums[right] >= i) {
                ++right;
            }
            ans = fmax(ans, (right - left - 1) * i);
            if (left == -1 && right == numsSize) {
                break;
            }
            i = fmax((left == -1 ? -1 : nums[left]), (right == numsSize ? -1 : nums[right]));
            if (i == -1) {
                break;
            }
        }
        return ans;

}
