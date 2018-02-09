bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    
    vector<TreeNode*> treeStack;
    TreeNode *leftNode, *rightNode;
    
    treeStack.push_back(root->left);
    treeStack.push_back(root->right);
    while (!treeStack.empty())
    {
        leftNode = treeStack.back();
        treeStack.pop_back();
        rightNode = treeStack.back();
        treeStack.pop_back();
        if (leftNode == NULL && rightNode == NULL) continue;
        if (leftNode == NULL || rightNode == NULL) return false;
        if (leftNode->val != rightNode->val) return false;
        treeStack.push_back(leftNode->left);
        treeStack.push_back(rightNode->right);
        treeStack.push_back(leftNode->right);
        treeStack.push_back(rightNode->left);
    }
    return true;
}