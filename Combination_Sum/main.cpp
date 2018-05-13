vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> curComb;
    sort(candidates.begin(), candidates.end());
    findCombSums(ret, curComb, candidates, target, 0);
    return ret;
}

//assume candidates has unique elements and sorted in order.
void findCombSums(vector<vector<int>>& ret, vector<int>& curComb, vector<int>& candidates, int remainder, int start)
{
    if (remainder < 0)
        return;
    if (remainder == 0)
    {
        ret.push_back(vector<int>(curComb));
        return;
    }
    for(int i = start; i < candidates.size(); i++)
    {
        curComb.push_back(candidates[i]);
        findCombSums(ret, curComb, candidates, remainder - candidates[i], i);
        curComb.pop_back();
    }
}