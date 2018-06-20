int longestValidParentheses(string s) {
    vector<int> stack = { 0 };
    int longest = 0;
    for (char& c : s)
    {
        if (c == '(')
        {
            stack.push_back(0);
        }
        else
        {
            if (stack.size() > 1)
            {
                int val = stack.back();
                stack.pop_back();
                stack.back() += val + 2;
                longest = max(longest, stack.back());
            }
            else
            {
                stack = { 0 };
            }
        }
    }
    return longest;
}