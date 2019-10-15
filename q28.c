#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    if (NULL == haystack || NULL == needle) {
        return 0;
    } 
    
    int sizHaystack = strlen(haystack);
    int sizNeedle   = strlen(needle);
    if (0 >= sizNeedle) {
        return 0;
    }
    
    char *check = needle;
    char *ptr   = haystack;
    
    for (int index = 0; index < sizHaystack; ++index) {
        if (*ptr != *check) {
            ptr += 1;
            continue;
        }
        
        int indexCheck = 0;
        if (sizNeedle > strlen(ptr)) {
            return -1;
        }
        
        for (indexCheck = 0; indexCheck < sizNeedle; ++indexCheck) {
            if (*(ptr + indexCheck) != *(check + indexCheck)) {
                break;
            }
        }
        
        if (sizNeedle == indexCheck) {
            return index;
        }
        
        ++ptr;
    } 
    
    return -1;
}

int
main(void) {
    int ret = strStr("hello", "ll");
    printf("%d\n", ret);

    return 0;
}
