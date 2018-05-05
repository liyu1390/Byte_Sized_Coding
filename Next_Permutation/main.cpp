void nextPermutation(vector<int>& nums) {
    int i = nums.size()-1;
    for(; i > 0; i--)
    {
        if (nums[i] > nums[i-1])
        {
            int ind = smallestLargerIndex(nums, i-1);
            swap(nums, ind, i-1);
            break;
        }
    }
    flip(nums, i, nums.size()-1);
}

void flip(vector<int>& nums, int start, int end)
{
    while(start < end)
    {
        swap(nums, start, end);
        start++;
        end--;
    }
}

void swap(vector<int>& nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int smallestLargerIndex(vector<int>& nums, int start)
{
    for(int i = nums.size() - 1; i > start; i--)
    {
        if (nums[i] > nums[start])
            return i;
    }
    return start;
}