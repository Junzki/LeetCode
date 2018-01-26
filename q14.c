/*
 * Problem #14
 * https://leetcode.com/problems/longest-common-prefix/
 */

#include <stdio.h>
#include <stdlib.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    int pos;
    int index;
    char c;
    char *res;
    
    pos = 0;
    index = 0;

    if (0 == strsSize)
        return "";
    
    c = strs[0][0];
    
    while ('\0' != c)
    {
        for (index = 0; index < strsSize; ++index)
        {
            char _c = strs[index][pos];
            if (_c != c || '\0' == _c)
                goto get_prefix;
        }

        ++pos;
        c = strs[0][pos];
    }

get_prefix:
    res = (char*)malloc((pos + 1) * sizeof(char));
    for (index = 0; index < pos; ++index)
    {
        res[index] = strs[0][index];
    }
    res[pos] = '\0';
    
    return res;
}
