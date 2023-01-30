// 链表节点
struct ListNode {
    // 值
    int val;
    // 下一个节点
    struct ListNode *next;
};

// 释放链表
void freeListNode(struct ListNode *node) {
    struct ListNode *tmp;
    while(node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}