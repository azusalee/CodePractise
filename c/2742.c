
/*
 2742. 给墙壁刷油漆
 给你两个长度为 n 下标从 0 开始的整数数组 cost 和 time ，分别表示给 n 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：

 一位需要 付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为 cost[i] 单位的钱。
 一位 免费 的油漆匠，刷 任意 一堵墙的时间为 1 单位，开销为 0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。
 请你返回刷完 n 堵墙最少开销为多少。
 
 整体来说就是让付费的去刷cost[i]/time[i]最小的墙，然后让免费的去刷cost[i]/time[i]最大的墙
 
 */

int min(int a, int b) {
    return a < b ? a : b;
}

int paintWalls(int *cost, int costSize, int *time, int timeSize){
    int n = costSize;
    int *f = (int *)malloc((n + 2) * sizeof(int));
    for (int i = 0; i < n + 2; i++) {
        f[i] = INT_MAX / 2;
    }
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n + 1; j >= 0; --j) {
            f[min(j + time[i], n) + 1] = min(f[min(j + time[i], n) + 1], f[j] + cost[i]);
        }
    }
    return min(f[n], f[n + 1]);
}
