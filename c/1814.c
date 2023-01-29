//
//  1814.c
//  CommonTool
//
//  Created by lizihong on 2023/1/17.
//  Copyright © 2023 AL. All rights reserved.
//

/*
1814. 统计一个数组中好对子的数目

给你一个数组 nums ，数组中只包含非负整数。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321 ， rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
请你返回好下标对的数目。由于结果可能会很大，请将结果对 109 + 7 取余 后返回。


来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-nice-pairs-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "1814.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int countNicePairs(int* nums, int numsSize){

    /*
    当反转后的数减去原来的数的值相同时，就说明两个数是好对子
    设rev为反转后的数，num为原数，offset为rev-num

    那么只需要统计各个offset的数量count就可以计算总共的好对子数目
    各个offset的好对子数目为，count*(count-1)/2

    使用哈希表，以offset为key，对应的数量为value储存

    由于c语言用哈希表比较麻烦，这里就不写实现了
    */ 

    
}
