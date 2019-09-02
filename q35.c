/*
 * Problem #35
 * https://leetcode.com/problems/search-insert-position/
 */

int searchInsert(int* nums, int numsSize, int target) {
    int index;
    
    for (index = 0; index < (numsSize - 1); ++index)
    {
        if (target <= nums[index])
            return index;
        
        else if (target > nums[index] && target <= nums[index + 1])
            return index + 1;
    }
    
    if (target <= nums[index])
        return index;
    
    return numsSize;
}

