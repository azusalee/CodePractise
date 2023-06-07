/*
 有两只老鼠和 n 块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。

 下标为 i 处的奶酪被吃掉的得分为：

 如果第一只老鼠吃掉，则得分为 reward1[i] 。
 如果第二只老鼠吃掉，则得分为 reward2[i] 。
 给你一个正整数数组 reward1 ，一个正整数数组 reward2 ，和一个非负整数 k 。

 请你返回第一只老鼠恰好吃掉 k 块奶酪的情况下，最大 得分为多少。

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/mice-and-cheese
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 这个其实就是一个找前k大的数的题目。

 用排序，时间复杂度为O(nlog(n)), 空间复杂度O(n)

 用优先排序，可以把复杂度降到O(nlog(k))
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// reward信息
struct RewardInfo {
    int reward1;
    int reward2;
    // reward1-reward2
    int diff;
};

 int compare(void* a, void* b) {
    
    struct RewardInfo *obj1 = *(struct RewardInfo**)a;
    struct RewardInfo *obj2 = *(struct RewardInfo**)b;
    
    return -obj1->diff+obj2->diff;
}

int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k){

    struct RewardInfo *rewardInfos[reward1Size];
    
    for (int i = 0; i < reward1Size; ++i) {
        struct RewardInfo *rewardInfo = malloc(sizeof(struct RewardInfo));
        rewardInfo->reward1 = reward1[i];
        rewardInfo->reward2 = reward2[i];
        rewardInfo->diff = reward1[i]-reward2[i];
        rewardInfos[i] = rewardInfo;
    }
    qsort(rewardInfos, reward1Size, sizeof(*rewardInfos), compare);
    
    int result = 0;
    for (int i = 0; i < k; ++i) {
        struct RewardInfo *rewardInfo = rewardInfos[i];
        result += rewardInfo->reward1;
    }
    for (int i = k; i < reward1Size; ++i) {
        struct RewardInfo *rewardInfo = rewardInfos[i];
        result += rewardInfo->reward2;
    }
    return result;
}