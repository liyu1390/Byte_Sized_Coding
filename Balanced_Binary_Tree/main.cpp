bool isBalanced(TreeNode* root) {
    if (height(root) == -1)
        return false;
    return true;
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    
    int leftHeight = height(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = height(root->right);
    if (rightHeight == -1) return -1;
    
    if (labs(leftHeight - rightHeight) > 1)
        return -1;
    return 1 + max(leftHeight, rightHeight);
}