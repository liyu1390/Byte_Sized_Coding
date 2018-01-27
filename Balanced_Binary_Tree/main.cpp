bool isBalanced(TreeNode* root) {
    if (maxHeight(root) - minHeight(root) < 2)
        return true;
    return false;
}

int minHeight(TreeNode* root){
    if (root == NULL)
        return 0;
    else 
        return 1 + min(minHeight(root->left), minHeight(root->right));
}

int maxHeight(TreeNode* root){
    if (root == NULL)
        return 0;
    else 
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
}