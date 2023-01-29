/*
2303. 计算应缴税款总额

给你一个下标从 0 开始的二维整数数组 brackets ，其中 brackets[i] = [upperi, percenti] ，表示第 i 个税级的上限是 upperi ，征收的税率为 percenti 。税级按上限 从低到高排序（在满足 0 < i < brackets.length 的前提下，upperi-1 < upperi）。

税款计算方式如下：

不超过 upper0 的收入按税率 percent0 缴纳
接着 upper1 - upper0 的部分按税率 percent1 缴纳
然后 upper2 - upper1 的部分按税率 percent2 缴纳
以此类推
给你一个整数 income 表示你的总收入。返回你需要缴纳的税款总额。与标准答案误差不超 10-5 的结果将被视作正确答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/calculate-amount-paid-in-taxes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income){
    // 按题意写逻辑即可
    int result = 0;
    int preUpper = 0;
    for (int i = 0; i < bracketsSize; ++i) {
        int upper = brackets[i][0];
        int percent = brackets[i][1];
        if (income <= upper) {
            result += (income-preUpper)*percent;
            // 由于收入已经比下一级的金额少，所以可以直接跳出循环了
            break;
        } else {
            result += (upper-preUpper)*percent;
        }
        preUpper = upper;
    }
    // 把计算出的数除以100，因为percent是百分比
    return (double)result/100;
}