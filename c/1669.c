/*
1669. 合并两个链表

给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-in-between-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "data_structure/list_node.h"

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    // 直接遍历模拟即可，O(m+n)
    struct ListNode *cur = list1;

    int index = 0;
    while(cur->next != NULL) {
        if (index == a-1) {
            break;
        }
        ++index;
        cur = cur->next;
    }

    struct ListNode *nodeA = cur->next;
    cur->next = list2;
    cur = nodeA;
    ++index;
    while(cur != NULL) {
        if (index == b) {
            break;
        }
        ++index;
        cur = cur->next;
    }
    struct ListNode *nodeB = cur;

    cur = list2;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = nodeB->next;
    nodeB->next = NULL;
    // 按理应该需要把a到b的节点free，不然会内存泄露
    while(nodeA != NULL) {
        nodeB = nodeA;
        nodeA = nodeA->next;
        free(nodeB);
    }

    return list1;
}