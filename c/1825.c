//
//  1825.c
//  CommonTool
//
//  Created by lizihong on 2023/1/18.
//  Copyright © 2023 AL. All rights reserved.
//

#include "1825.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 这题可以使用跳表的数据结构实现，做到插入的时间复杂度为O(log(m))，计算平均值时间为O(1)
 因为跳表的时间复杂度，插入，删除，查找都是O(log(n))
 
 大概思路是分开3个有序跳表
 表1 0~k-1
 表2 k~m-k-1
 表3 m-k~m-1
 
 每次插入时维护这三个表
 由于只需要插入顺序的后m个数，所以长度达到m之后，每次插入，都需要先把前一个数删除，O(log(m))
 然后再插入到合适的位置，O(log(m))
 如果插入的是表1，且表1的个数已达到k+1，此时把最后数移到表2，如果表2个数达到m-2*k+1，那么把表2最后一个数移到表3
 如果插入的是表2，如果表2个数达到m-2*k+1，如果表1的个数不足k，那么把表2第一个数移到表1，反之把表2最后一个数移到表3
 如果插入的是表3，且表3的个数已达到k+1，此时把表3第一个数移到表2，如果表2个数达到m-2*k+1，那么把表2第一个数移到表1
 
 同时维护表2的合计值
 
 然后计算表2的平均值就可以，计算只需要O(1)的时间复杂度
 
 */

typedef struct {
    int m;
    int k;
} MKAverage;


MKAverage* mKAverageCreate(int m, int k) {
    MKAverage *obj = malloc(sizeof(MKAverage));
    
    return obj;
}

void mKAverageAddElement(MKAverage* obj, int num) {
   
}

int mKAverageCalculateMKAverage(MKAverage* obj) {
 
    
}

void mKAverageFree(MKAverage* obj) {

}
