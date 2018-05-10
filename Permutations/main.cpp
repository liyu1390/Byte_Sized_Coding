vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms;
    vector<int> perm = {};
    vector<bool> bools(nums.size(), false);
    
    dsfPermSearch(perms, perm, bools, nums);
    
    return perms;
}

void dsfPermSearch(vector<vector<int>>& perms, vector<int>& curPerm, vector<bool>& curBools, vector<int>& nums)
{
    if (curPerm.size() == nums.size())
    {
        perms.push_back(vector<int>(curPerm));
        return;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (curBools[i] == true) continue;
        curBools[i] = true;
        curPerm.push_back(nums[i]);
        dsfPermSearch(perms, curPerm, curBools, nums);
        curPerm.pop_back();
        curBools[i] = false;
    }
}