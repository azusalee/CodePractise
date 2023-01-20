//
//  753.c
//  CommonTool
//
//  Created by lizihong on 2023/1/10.
//  Copyright © 2023 AL. All rights reserved.
//

#include "753.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
有一个需要密码才能打开的保险箱。密码是 n 位数, 密码的每一位都是范围 [0, k - 1] 中的一个数字。

保险箱有一种特殊的密码校验方法，你可以随意输入密码序列，保险箱会自动记住 最后 n 位输入 ，如果匹配，则能够打开保险箱。

例如，正确的密码是 "345" ，并且你输入的是 "012345" ：
输入 0 之后，最后 3 位输入是 "0" ，不正确。
输入 1 之后，最后 3 位输入是 "01" ，不正确。
输入 2 之后，最后 3 位输入是 "012" ，不正确。
输入 3 之后，最后 3 位输入是 "123" ，不正确。
输入 4 之后，最后 3 位输入是 "234" ，不正确。
输入 5 之后，最后 3 位输入是 "345" ，正确，打开保险箱。
在只知道密码位数 n 和范围边界 k 的前提下，请你找出并返回确保在输入的 某个时刻 能够打开保险箱的任一 最短 密码序列 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cracking-the-safe
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
题目的意思简单来说就是： 用最短的字符串列出所有可能的密码

所有密码共有k^n种的搭配

这题可以看作求欧拉回路的题目。一次性不重复地走完所有的边且回到该节点，也就是一笔画问题。
以前n-1位为节点，后一位有k种可能，假设其可以不重复地走完所有可能，那么最终长度是n^k+n-1
欧拉回路存在需要满足：(1)入度=出度；(2)图是连通的
由于任意一个n-1的子串都可以往后添加[0,k)转移到一个新的节点上，所以每个节点有k条出边，
同理它也有k条入边，(1)是满足的。下面检查连通性，假设现在要从abc转移到任意一个节点xyz，
先在后面添加一个x得到bcx（只保留长度为3的后缀，相当于abc经过边abcx到达点bcx），
再在后面添加一个y得到cxy，最后添加一个z得到xyz，因此任意两个点都是连通的。

Hierholzer 算法可以在一个欧拉图中找出欧拉回路

时间复杂度：O(n×k^n)。
空间复杂度：O(n×k^n)。
*/

#define N 10000
int visited[N];
char str[N];
int len, k_rec;
int highest;

void dfs(int node) {
    for (int x = 0; x < k_rec; ++x) {
        int nei = node * 10 + x;
        // 判断该数字是否已经遍历过，防止重复遍历
        if (!visited[nei]) {
            visited[nei] = 1;
            // 保留末尾n-1位数，继续遍历
            dfs(nei % highest);
            str[len++] = x + '0';
        }
    }
}

char *crackSafe(int n, int k) {
    memset(visited, 0, sizeof(visited));
    memset(str, 0, sizeof(str));
    k_rec = k, len = 0;
    visited[0] = true;
    // 计出最高位数mod，用于截取后n-1位数
    highest = pow(10, n - 1);
    dfs(0);
    for (int i = 0; i < n; i++) {
        str[len++] = '0';
    }
    return str;
}

