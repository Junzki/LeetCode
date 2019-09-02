#include <stdio.h>

/*
 * However, I did not really understand this solution,
 * some similiar problems should be reviewed in the near future.
 */

int
maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) {
        return nums[0];
    }
    
    int sum = nums[0];
    int index = 1;
    int max = sum;
    
    for (index = 1; index < numsSize; ++index) {
        sum += nums[index];
        
        if (sum < nums[index]) {
            sum = nums[index];
        }
        
        if (sum > max) {
            max = sum;
        }
    }
    
    return max;
}


int
main(void) {
	int input[] = {-2,1,-3,4,-1,2,1,-5,4};
	int ret = maxSubArray(input, 9);

	printf("%d\n", ret);

	return 0;
}
