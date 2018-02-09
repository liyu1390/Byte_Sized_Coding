bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    
    vector<TreeNode*> leftTree, rightTree;
    leftTree.push_back(root->left);
    rightTree.push_back(root->right);
    TreeNode *leftNode, *rightNode;
    
    while (!leftTree.empty() && !rightTree.empty())
    {
        leftNode = leftTree.back();
        rightNode = rightTree.back();
        
        leftTree.pop_back();
        rightTree.pop_back();
        
        if (leftNode && rightNode)
        {
            if (leftNode->val != rightNode->val)
            {
                return false;
            }
            else
            {
                leftTree.push_back(leftNode->left);
                leftTree.push_back(leftNode->right);
                rightTree.push_back(rightNode->right);
                rightTree.push_back(rightNode->left);
            }
        }
        else if (!leftNode && !rightNode)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if (leftTree.empty() && rightTree.empty())
        return true;
    return false; 
}