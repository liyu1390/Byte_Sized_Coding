vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curComb;
    
    dsfCombFinder(combs, curComb, n, k, 0);
    
    return combs;
}

void dsfCombFinder(vector<vector<int>>& combs, vector<int>& curComb, int n, int k, int cur)
{
    int size = curComb.size();
    if (size == k)
    {
        combs.push_back(vector<int>(curComb));
        return;
    }

    for(; cur < n - k + size + 1; ++cur)
    {
        curComb.push_back(cur+1);
        dsfCombFinder(combs, curComb, n, k, cur+1);
        curComb.pop_back();
    }
}