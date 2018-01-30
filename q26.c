/**
 * Problem #26
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

int removeDuplicates(int* nums, int numsSize) {
    int cur;
    int index;

    index = 1;
    if (0 == numsSize || 1 == numsSize)
        return numsSize;

    cur = nums[0];
    while(index < numsSize)
    {
        if (nums[index] != cur)
        {
            cur = nums[index];
            ++index;
            continue;
        }

        int _in;
        for (_in = index; _in < numsSize; ++_in)
            nums[_in] = nums[_in + 1];

        --numsSize;
    }

    return numsSize;
}
