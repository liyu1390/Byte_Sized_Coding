vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> curComb;
    sort(candidates.begin(), candidates.end());
    findCombSums(ret, curComb, candidates, 0, target);
    return ret;
}

//assume candidates has unique elements and sorted in order.
//returns true if we have found a candidate.
void findCombSums(vector<vector<int>>& ret, vector<int>& curComb, vector<int>& candidates, int checkInd, int remainder)
{
    if (remainder == 0)
    {
        ret.push_back(vector<int>(curComb));
        return;
    }
    if (checkInd >= candidates.size() || candidates[checkInd] > remainder) 
        return;
    
    int candidate = candidates[checkInd];
    int maxRep = remainder/candidate;
    int i;
    for(i = 0; i < maxRep; i++)
    {
        curComb.push_back(candidate);
    }
    for(; i > 0; i--)
    {
        findCombSums(ret, curComb, candidates, checkInd+1, remainder - candidate*i);
        curComb.pop_back();
    }
    findCombSums(ret, curComb, candidates, checkInd+1, remainder);   
}