int combinationSum4(vector<int>& nums, int target) {
    vector<int> combs(target + 1, 0);
    combs[0] = 1;
    for(int i = 0; i <= target; i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(i - nums[j] >= 0)
            {
                combs[i] += combs[i - nums[j]];
            }
        }
    }
    return combs[target];
}