bool isValid(string s) {
    list<char> stack;
    map<char, char> pairings;
    pairings[')'] = '(';
    pairings['}'] = '{';
    pairings[']'] = '[';
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (pairings.count(s[i]) == 0)
            stack.push_back(s[i]);
        else if (!stack.empty() && stack.back() == pairings[s[i]])
            stack.pop_back();
        else
            return false;
    }
    if (stack.empty())
        return true;
    return false;
}