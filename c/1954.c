/*
 1954. 收集足够苹果的最小花园周长
 给你一个用无限二维网格表示的花园，每一个 整数坐标处都有一棵苹果树。整数坐标 (i, j) 处的苹果树有 |i| + |j| 个苹果。

 你将会买下正中心坐标是 (0, 0) 的一块 正方形土地 ，且每条边都与两条坐标轴之一平行。

 给你一个整数 neededApples ，请你返回土地的 最小周长 ，使得 至少 有 neededApples 个苹果在土地 里面或者边缘上。

 |x| 的值定义为：

 如果 x >= 0 ，那么值为 x
 如果 x < 0 ，那么值为 -x
 */

// 遍历
long long minimumPerimeter(long long neededApples) {
    /*
     假设每一圈的总数为f(n)
     那么有f(0) = 0;
     f(n) = f(n-1)+24*n-12;
     f(n) = 24*n-12+24*(n-1)-12+24*(n-2)-12+...+0
     f(n) = 24*(1+2+...+n)-12*n;
     f(n) = 24*(n*(n+1))/2-12*n
     f(n) = 12*(n*(n+1))-12*n
     f(n) = 12*n^2
     
     设总数为t(n)
     那么有
     t(n) = f(n)+f(n-1)+...+f(1)+f(0)
     t(n) = 12*(n^2+(n-1)^2+...+1^2)
     t(n) = 12*n*(n+1)*(2*n+1)/6
     t(n) = 2*n*(n+1)*(2*n+1)
     */
    
    long long i = 0;
    while (2*i*(i+1)*(2*i+1) < neededApples) {
        i += 1;
    }
    return i*8;
}

// 二分法
long long minimumPerimeter(long long neededApples) {
    long long left = 1, right = 100000, ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (2 * mid * (mid + 1) * (mid * 2 + 1) >= neededApples) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans * 8;
}

