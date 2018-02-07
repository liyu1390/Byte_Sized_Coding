vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> paths;
    vector<int> path;
    if (root == NULL)
        return paths;
    findPaths(root, sum, path, paths);
    return paths;
}

void findPaths(TreeNode* root, int remainder, vector<int>& path, vector<vector<int>>& paths){
    path.push_back(root->val);
    if (root->left != NULL) {
        findPaths(root->left, remainder - root->val, path, paths);
    }
    if (root->right != NULL) {
        findPaths(root->right, remainder - root->val, path, paths);
    }
    if (root->left == NULL && root->right == NULL && remainder == root->val) {
        paths.push_back(path);
    }
    path.pop_back();
}