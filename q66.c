/**
 * Problem #66
 * https://leetcode.com/problems/plus-one/
 */

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int overflow = 1;
    
    int index = digitsSize - 1;
    for (index; index >= 0; --index) {
        int v = digits[index] + overflow;
        if (v <= 9) {
            digits[index] = v;
            overflow = 0;
            continue;
        }
        
        digits[index] = 0;
        overflow = 1;
    }
    
    if (0 == overflow) {
        *returnSize = digitsSize;
        return digits;
    }
    
    *returnSize = digitsSize + 1;
    
    int* returnDigits = NULL;
    returnDigits = (int *)malloc((*returnSize)*sizeof(int));
    
    returnDigits[0] = 1;
    for (index = 1; index <= digitsSize; ++index) {
        returnDigits[index] = digits[index - 1];
    }
    
    return returnDigits;
}

