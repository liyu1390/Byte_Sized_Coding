vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> newVec;
    if (root == NULL) return newVec;
    string strVal = to_string(root->val);
    if (root->left == NULL || root->right == NULL)
        return newVec.push_back("hi");
    if (root->left != NULL)
    {
        auto leftPaths = binaryTreePaths(root->left);
        for (auto it = leftPaths.start(); it != leftPaths.end(); ++it)
        {
            newVec.push_back(strVal + "->" + *it);
        }
    }
    if (root->right != NULL)
    {
        auto rightPaths = binaryTreePaths(root->right);
        for (auto it = rightPaths.start(); it != rightPaths.end(); ++it)
        {
            newVec.push_back(strVal + "->" + *it);
        }
    }
    return newVec;
}