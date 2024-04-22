/*
 https://leetcode.cn/problems/beautiful-towers-ii/description/
 2866. 美丽塔 II
 给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。

 你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。

 如果以下条件满足，我们称这些塔是 美丽 的：

 1 <= heights[i] <= maxHeights[i]
 heights 是一个 山脉 数组。
 如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：

 对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
 对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
 请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
 */

long long maximumSumOfHeightsHelper(int* maxHeights, int maxHeightsSize, int maxIndex){
    long long result = 0;
    
    int i = maxIndex;
    int currentHeight = maxHeights[maxIndex];
    
    while(i >= 0) {
        if (maxHeights[i] < currentHeight) {
            currentHeight = maxHeights[i];
        }
        result += currentHeight;
        i -= 1;
    }
    
    i = maxIndex+1;
    currentHeight = maxHeights[maxIndex];
    while (i < maxHeightsSize) {
        if (maxHeights[i] < currentHeight) {
            currentHeight = maxHeights[i];
        }
        result += currentHeight;
        i += 1;
    }
    
    return result;
}

long long maximumSumOfHeights(int* maxHeights, int maxHeightsSize){
    
//    int maxIndex = 0;
//    int maxValue = 0;
//    for (int i = 0; i < maxHeightsSize; ++i) {
//        if (maxHeights[i] > maxValue) {
//            maxValue = maxHeights[i];
//            maxIndex = i;
//        }
//    }
    
    // 暴力解法O(n^2)，会超时
    int i = 0;
    long long maxResult = 0;
    int leftHeight = 0;
    int rightHeight = 0;
    if (maxHeightsSize > 1) {
        rightHeight = maxHeights[1];
    }
    
    while (i < maxHeightsSize) {
        if (maxHeights[i] > leftHeight && maxHeights[i] >= rightHeight) {
            long long result = maximumSumOfHeightsHelper(maxHeights, maxHeightsSize, i);
            if (result > maxResult) {
                maxResult = result;
            }
            i += 1;
        }
        leftHeight = maxHeights[i];
        if (i+1 < maxHeightsSize) {
            rightHeight = maxHeights[i+1];
        } else {
            rightHeight = 0;
        }
        
        i += 1;
    }
    
    return maxResult;
}

long long maximumSumOfHeights(int* maxHeights, int maxHeightsSize){
    // 单调栈，O(n), 空间O(n)
    
    int n = maxHeightsSize;
    long long res = 0;
    // 前缀值和，后缀值和
    long long prefix[n], suffix[n];
    // 记录低位位置的栈
    int stack1[n], stack2[n];
    int top1 = 0, top2 = 0;
    // 计算前缀值
    for (int i = 0; i < n; i++) {
        while (top1 > 0 && maxHeights[i] < maxHeights[stack1[top1 - 1]]) {
            top1--;
        }
        if (top1 == 0) {
            prefix[i] = (long long)(i + 1) * maxHeights[i];
        } else {
            prefix[i] = prefix[stack1[top1 - 1]] + (long long)(i - stack1[top1 - 1]) * maxHeights[i];
        }
        stack1[top1++] = i;
    }
    // 计算后缀值
    for (int i = n - 1; i >= 0; i--) {
        while (top2 > 0 && maxHeights[i] < maxHeights[stack2[top2 - 1]]) {
            top2--;
        }
        if (top2 == 0) {
            suffix[i] = (long long)(n - i) * maxHeights[i];
        } else {
            suffix[i] = suffix[stack2[top2 - 1]] + (long long)(stack2[top2 - 1] - i) * maxHeights[i];
        }
        stack2[top2++] = i;
        res = fmax(res, prefix[i] + suffix[i] - maxHeights[i]);
    }
    return res;
    
}
