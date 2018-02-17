struct Frame
{
    TreeNode* node;
    vector<TreeNode*> subs;
    Frame* parent;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    Frame answer;
    stack<Frame> stack;
    stack.push({root, &answer});
    while(!stack.empty())
    {
        Frame *top = &stack.top(), *parent = &top->parent;
        TreeNode* node = top->node;
        if (top->node == NULL || top->node == p || top->node == q)
        {
            parent->subs.push_back(node);
            stack.pop();
        }
        else if(top->subs.empty())
        {
            stack.push({node->right, top})
            stack.push({node->left, top})
        }
        else
        {
            TreeNode *left = top->subs[0], *right = top->sub[1];
            parent->subs.push_back(!left ? right : !right ? left : node);
            stack.pop()
        }
    }
    return answer.subs[0];
}