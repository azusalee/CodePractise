
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode* tree;
} FindElements;

void recoverTree(struct TreeNode* root) {
    if (root->left != NULL) {
        root->left->val = root->val*2+1;
        recoverTree(root->left);
    }
    if (root->right != NULL) {
        root->right->val = root->val*2+2;
        recoverTree(root->right);
    }
}

FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements* obj = malloc(sizeof(FindElements*));
    obj->tree = root;
    root->val = 0;
    recoverTree(root);
    return obj;
}

bool findElementsFind(FindElements* obj, int target) {
    int actions[20] = {0};
    int count = 0;
    int value = target;
    while(value > 0) {
        actions[count++] = ((value%2) == 1)?0:1;
        value = (value-1)/2;
    }
    struct TreeNode* node = obj->tree;
    while(count > 0) {
        if (actions[count-1] == 0) {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node == NULL) {
            return false;
        }
        count -= 1;
    }
    
    return true;
}

void findElementsFree(FindElements* obj) {
    free(obj);
}
