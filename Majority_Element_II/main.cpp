vector<int> majorityElement(vector<int>& nums) {
    vector<int> candidates = {NULL, NULL};
    vector<int> counts = {0,0};
    vector<int> ret;

    for (auto num : nums)
    {
        if (candidates[0] == num)
            counts[0]++;
        else if(candidates[1] == num)
            counts[1]++;
        else if (counts[0] == 0)
        {
            candidates[0] = num;
            counts[0]++;
        }
        else if(counts[1] == 0)
        {
            candidates[1] = num;
            counts[1]++;
        }
        else
        {
            counts[0]--;
            counts[1]--;
        }
    }
    
    counts[0] = 0;
    counts[1] = 0;
    for(auto num : nums)
    {
        if (num == candidates[0])
            counts[0]++;
        else if (num == candidates[1])
            counts[1]++;
    }
    
    if (counts[0] > nums.size()/3)
        ret.push_back(candidates[0]);
    if (counts[1] > nums.size()/3)
        ret.push_back(candidates[1]);
    return ret;
}