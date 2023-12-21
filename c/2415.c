/*
 https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2023-12-15
 2415, 翻转二叉树的奇数层
 
 给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。

 例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
 反转后，返回树的根节点。

 完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。

 节点的 层数 等于该节点到根节点之间的边数
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void replaceNode(struct TreeNode* left, struct TreeNode* right, bool isOdd) {
    if (left == NULL) {
        return;
    }
    if (isOdd) {
        // 奇数层
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
    replaceNode(left->left, right->right, !isOdd);
    replaceNode(left->right, right->left, !isOdd);
    
}
 
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    replaceNode(root->left, root->right, true);
    return root;
}
