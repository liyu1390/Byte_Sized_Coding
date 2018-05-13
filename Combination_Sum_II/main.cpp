vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<bool> usedTracker(candidates.size(), false);
    vector<int> curComb;
    vector<vector<int>> ret;
    
    getCombSumSets(ret, curComb, candidates, usedTracker, target, 0);
    
    return ret;
    
}

void getCombSumSets(vector<vector<int>>& ret, vector<int>& curComb, vector<int>& candidates, vector<bool>& usedTracker, int remainder, int startIndex)
{
    if (remainder <= 0)
    {
        if (remainder == 0)
            ret.push_back(vector<int>(curComb));  
        return;
    }
    
    int size = candidates.size();
    
    for(int i = startIndex; i < size; i++)
    {
        if (i != 0 && candidates[i] == candidates [i-1] && !usedTracker[i-1])
            continue;
        usedTracker[i] = true;
        curComb.push_back(candidates[i]);
        getCombSumSets(ret, curComb, candidates, usedTracker, remainder - candidates[i], i+1);
        curComb.pop_back();
        usedTracker[i] = false;
    }
}