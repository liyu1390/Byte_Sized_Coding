vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> perms;
    while (perms.empty() || perms.front() != nums)
    {
        vector<int> perm(nums);
        perms.push_back(perm);
        nextPermutation(nums);
    }
    return perms;
}

void nextPermutation(vector<int>& nums)
{
    int i = nums.size() - 1;
    for(; i > 0; i--)
    {
        if (nums[i] > nums[i-1])
        {
            int swapIndex = getNextPermValue(nums, i-1);
            swapValues(nums, i-1, swapIndex);
            break;
        }
    }
    flipSection(nums, i, nums.size()-1);
}

//the nums after start should be in decreasing order
//check starting from the back and get index of first value larger than nums[start]
int getNextPermValue(const vector<int>& nums, int start)
{
    int i = nums.size() - 1;
    int startVal = nums[start];
    for(; i > start; i--)
    {
        if (nums[i] > startVal) 
            return i;
    }
    return start;
}

void swapValues(vector<int>& nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void flipSection(vector<int>& nums, int a, int b)
{
    while(a < b)
    {
        swapValues(nums, a, b);
        a++;
        b--;
    }
}