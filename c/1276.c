/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 *1276. 不浪费原料的汉堡制作方案
 *
 *圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。
 
 给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：

 巨无霸汉堡：4 片番茄和 1 片奶酪
 小皇堡：2 片番茄和 1 片奶酪
 请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。

 如果无法使剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量为 0，就请返回 []。
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize) {
    // 如果要刚好用完材料，根据题目有以下两条式子
    // 假设 巨无霸汉堡数为m, 小皇堡数为n
    // m+n = cheeseSlices;
    // 4*m+2*n = tomatoSlices;
    // 4*(cheeseSlices-n)+2*n = tomatoSlices
    // 4*cheeseSlices-2*n = tomatoSlices
    // n = (4*cheeseSlices-tomatoSlices)/2
    int n_2 = 4*cheeseSlices-tomatoSlices;
    int *result = malloc(sizeof(int)*2);
    if (n_2%2 == 0) {
        int n = n_2/2;
        int m = cheeseSlices-n;
        if (m >= 0 & n >= 0) {
            *returnSize = 2;
            
            result[0] = m;
            result[1] = n;
        } else {
            *returnSize = 0;
        }
    } else {
        *returnSize = 0;
    }
    return result;
}
