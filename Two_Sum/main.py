def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    compToIndex = {};
    for i in range(len(nums)):
        comp = target - nums[i];
        if comp in compToIndex:
            return [compToIndex[comp], i];
        compToIndex[nums[i]] = i;
    return None;
