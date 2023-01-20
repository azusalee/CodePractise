//
//  1817.c
//  CommonTool
//
//  Created by lizihong on 2023/1/20.
//  Copyright © 2023 AL. All rights reserved.
//

#include "1817.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 给你用户在 LeetCode 的操作日志，和一个整数 k 。日志用一个二维整数数组 logs 表示，其中每个 logs[i] = [IDi, timei] 表示 ID 为 IDi 的用户在 timei 分钟时执行了某个操作。

 多个用户 可以同时执行操作，单个用户可以在同一分钟内执行 多个操作 。

 指定用户的 用户活跃分钟数（user active minutes，UAM） 定义为用户对 LeetCode 执行操作的 唯一分钟数 。 即使一分钟内执行多个操作，也只能按一分钟计数。

 请你统计用户活跃分钟数的分布情况，统计结果是一个长度为 k 且 下标从 1 开始计数 的数组 answer ，对于每个 j（1 <= j <= k），answer[j] 表示 用户活跃分钟数 等于 j 的用户数。

 返回上面描述的答案数组 answer 。

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/finding-the-users-active-minutes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 方法1 (O(nlog(n)))
 先排序logs, 先按id排序，id相同再按时间排序(升序或降序都可以)
 
 设返回结果的数组为 int *result
 遍历已排序的logs,
 与前一个id相同且时间不同的时候，count+1
 与前一个id不同时，对应result[count-1]++，然后设count=1
 遍历完后，把最后的count计上，result[count-1]++
 
 此时result就是答案了
 */

/*
 方法2 (O(n+idCount), idCount是不同id的数量)
 
 通过hash表记录，每个id有多少个不同的时间，然后再遍历hash表，计算结果即可
 
 由于c语言用hash表比较麻烦，这里就不写实现了
 
 */

int compare(void* a, void* b) {
    
    int *log1 = *(int**)a;
    int *log2 = *(int**)b;
    
    if (log1[0] == log2[0]) {
        return log1[1]-log2[1];
    }
    
    return log1[0]-log2[0];
}

int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize){
    
    int *result = malloc(sizeof(int)*k);
    memset(result, 0, sizeof(int)*k);
    qsort(logs, logsSize, sizeof(*logs), compare);
    
    int count = 0;
    for (int i = 0; i < logsSize; ++i) {
        if (i > 0) {
            if (logs[i][0] == logs[i-1][0]) {
                if (logs[i][1] != logs[i-1][1]) {
                    count += 1;
                }
            } else {
                result[count-1] += 1;
                count = 1;
            }
        } else {
            count = 1;
        }
    }
    result[count-1] += 1;
    
    *returnSize = k;
    return result;
    
}
