vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (root == NULL) return result;
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}

void binaryTreePaths(vector<string>& paths, TreeNode* root, string curString)
{
    if (root->left) binaryTreePaths(paths, root->left, curString + "->" + to_string(root->left->val));
    if (root->right) binaryTreePaths(paths, root->right, curString + "->" + to_string(root->right->val));
    if (!root->left && !root->right) paths.push_back(curString);
}