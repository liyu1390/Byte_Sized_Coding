vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> currentComb;
    
    getCombinations(ret, currentComb, k, 1, n);
    
    return ret;
}

void getCombinations(vector<vector<int>>& ret, vector<int>& currentComb, int k, int start, int remainder)
{
    if (remainder < 0 || currentComb.size() > k)
        return;
    if (remainder == 0 && currentComb.size() == k)
    {
        ret.push_back(vector<int>(currentComb));
        return;
    }
    
    for(int i = start; i <= 9; i++)
    {
        currentComb.push_back(i);
        getCombinations(ret, currentComb, k, i+1, remainder-i);
        currentComb.pop_back();
    }
}