double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    switchSmallerToFirst(nums1, nums2);
    int m = nums1.size(), n = nums2.size();
    int imin = 0, imax = m;
    int halfSize = (nums1.size() + nums2.size() + 1)/2;
    while (true)
    {
        i = (imin + imax)/2;
        j = halfSize - i;
        if ((i == 0 or j == n or (nums1[i-1] <= nums2[j]))
             and (j == 0 or i == m or (nums2[j-1] <= num1[i])))
        {
            
        }
        else if (nums1[cutOne-1] > nums2[cutTwo])
        {
            imax = i - 1;
        }
        else if (nums1[cutOne] < nums2[cutTwo-1])
        {
            imin = i + 1;
        }
    }
}

void switchSmallerToFirst(vector<int>* nums1, vector<int>* nums2)
{
    if (nums1->size() > nums2->size())
    {
        vector<int>* tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
    }
}