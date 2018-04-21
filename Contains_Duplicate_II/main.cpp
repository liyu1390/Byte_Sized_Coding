bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> seen;
    for(int i = 0; i < nums.size(); i++)
    {
        if(seen.find(nums[i]) != seen.end() && abs(i - seen.find(nums[i])->second) <= k)
        {
            return true;
        }
        else
        {
            seen[nums[i]] = i;
        }
    }
    return false;
}