/*
1828. 统计一个圆中点的数目

给你一个数组 points ，其中 points[i] = [xi, yi] ，表示第 i 个点在二维平面上的坐标。多个点可能会有 相同 的坐标。

同时给你一个数组 queries ，其中 queries[j] = [xj, yj, rj] ，表示一个圆心在 (xj, yj) 且半径为 rj 的圆。

对于每一个查询 queries[j] ，计算在第 j 个圆 内 点的数目。如果一个点在圆的 边界上 ，我们同样认为它在圆 内 。

请你返回一个数组 answer ，其中 answer[j]是第 j 个查询的答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries,
 int queriesSize, int* queriesColSize, int* returnSize){

    // 按题意，暴力求解 O(m*n)
    int *result = malloc(sizeof(int)*queriesSize);
    memset(result, 0, sizeof(int)*queriesSize);

    for (int i = 0; i < queriesSize; ++i) {
        int x = queries[i][0];
        int y = queries[i][1];
        int r = queries[i][2];
        int r2 = r*r;
        for (int j = 0; j < pointsSize; ++j) {
            int xlen = x-points[j][0];
            int ylen = y-points[j][1];
            // 计算点是否在圆内(与圆心距离是否不大于半径)
            if (xlen*xlen+ylen*ylen <= r2) {
                result[i] += 1;
            }
        }
    }

    *returnSize = queriesSize;
    return result;
}