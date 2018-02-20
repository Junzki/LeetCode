/**
 * Problem #27
 * https://leetcode.com/problems/remove-element/
 */

int removeElement(int* nums, int numsSize, int val) {
    int index;
    int length = numsSize;
    
    if (0 == numsSize)
        return 0;
    
    index = 0;
    
    while (index < length)
    {
        int ptr;
        if (nums[index] != val)
        {
            ++index;
            continue;
        }
        
        for (ptr = index; ptr < (numsSize-1); ++ptr)
        {
            nums[ptr] = nums[ptr+1];
        }
        --length;
    }
    
    return length;
}
