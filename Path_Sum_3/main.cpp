int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int sumUp(TreeNode* node, int remainder) {
    if (!node) return 0;
    remainder -= node->val;
    return (remainder == 0) + sumUp(node->left, remainder) + sumUp(node->right, remainder);
}