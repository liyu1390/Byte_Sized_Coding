double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int cutOne = 0, cutTwo = 0;
    int lower = 0, upper = nums1.size()-1;
    int halfSize = (nums1.size() + nums2.size())/2;
    while (true)
    {
        cutOne = (upper+lower)/2;
        cutTwo = halfSize - cutOne;
        if (nums1[cutOne-1] > nums2[cutTwo])
        {
            upper = cutOne;
        }
        else if (nums1[cutOne] < nums2[cutTwo-1])
        {
            lower = cutOne;
        }
        else
        {
            break;
        }
    }
    return nums1[cutOne];
}