TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;
    if (isIn(root->left, p) && isIn(root->left, q)) return lowestCommonAncestor(root->left, p, q);
    if (isIn(root->right, p) && isIn(root->right, q)) return lowestCommonAncestor(root->right, p, q);
    return root;
    
}

bool isIn(TreeNode* root, TreeNode* k)
{
    if (root == NULL) return false;
    if (root == k) return true;
    return isIn(root->left, k) || isIn(root->right, k);
}