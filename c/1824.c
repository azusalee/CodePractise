/*
1824. 最少侧跳次数

给你一个长度为 n 的 3 跑道道路 ，它总共包含 n + 1 个 点 ，编号为 0 到 n 。一只青蛙从 0 号点第二条跑道 出发 ，它想要跳到点 n 处。然而道路上可能有一些障碍。

给你一个长度为 n + 1 的数组 obstacles ，其中 obstacles[i] （取值范围从 0 到 3）表示在点 i 处的 obstacles[i] 跑道上有一个障碍。如果 obstacles[i] == 0 ，那么点 i 处没有障碍。任何一个点的三条跑道中 最多有一个 障碍。

比方说，如果 obstacles[2] == 1 ，那么说明在点 2 处跑道 1 有障碍。
这只青蛙从点 i 跳到点 i + 1 且跑道不变的前提是点 i + 1 的同一跑道上没有障碍。为了躲避障碍，这只青蛙也可以在 同一个 点处 侧跳 到 另外一条 跑道（这两条跑道可以不相邻），但前提是跳过去的跑道该点处没有障碍。

比方说，这只青蛙可以从点 3 处的跑道 3 跳到点 3 处的跑道 1 。
这只青蛙从点 0 处跑道 2 出发，并想到达点 n 处的 任一跑道 ，请你返回 最少侧跳次数 。

注意：点 0 处和点 n 处的任一跑道都不会有障碍。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-sideway-jumps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define MIN(X, Y) ((Y)<(X)?(Y):(X))

int minSideJumps(int* obstacles, int obstaclesSize){
    // 动态规划，计算在每一步的每一条道上的最小侧跳数
    int INF = 0x3f3f3f3f;
    int jump[3] = {1, 0, 1};
    for (int i = 1; i < obstaclesSize; ++i) {

        int index = obstacles[i]-1;
        int minCnt = INF;
        for (int j = 0; j < 3; ++j) {
            if (index == j) {
                // 由于这条路在这一步被阻挡，所以设置为一个极大值，代表其无法通过
                jump[j] = INF;
            } else {
                // 找出当前最小值
                minCnt = MIN(jump[j], minCnt);
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (index == j) {
                // 由于被阻挡，所以这条道无法跳过去
                continue;
            }
            // 更新最小值(在当前道不变，或者从当前最小侧跳数道跳过来)
            jump[j] = MIN(jump[j], minCnt+1);
        }
    }
    // 返回3条道中最小的数
    return MIN(MIN(jump[0], jump[1]), jump[2]);
}