vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> paths;
    vector<int> path;
    findPaths(root, sum, path, paths);
    return paths;
}

void findPaths(TreeNode* root, int remainder, vector<int>& path, vector<vector<int>>& paths){
    if (root == NULL)
        return;
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL && remainder == root->val) {
        paths.push_back(path);
    }
    findPaths(root->left, remainder - root->val, path, paths);
    findPaths(root->right, remainder - root->val, path, paths);
    path.pop_back();
}