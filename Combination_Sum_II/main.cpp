vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> curComb;
    vector<vector<int>> ret;
    
    getCombSumSets(ret, curComb, candidates, target, 0);
    
    return ret;
    
}

void getCombSumSets(vector<vector<int>>& ret, vector<int>& curComb, vector<int>& candidates, int remainder, int startIndex)
{   
    if (remainder < 0)
        return;
    
    if (remainder == 0)
    {
        ret.push_back(vector<int>(curComb));  
        return;
    }
    
    int size = candidates.size();
    
    for(int i = startIndex; i < size; i++)
    {
        if (i > startIndex && candidates[i] == candidates [i-1])
            continue;
        curComb.push_back(candidates[i]);
        getCombSumSets(ret, curComb, candidates, remainder - candidates[i], i+1);
        curComb.pop_back();
    }
}