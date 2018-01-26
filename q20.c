/*
 * Problem #20
 * https://leetcode.com/problems/valid-parentheses/
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isValid(char* s) {
    unsigned long length;
    char *heap;
    char *heap_ptr;
    char *heap_tail;
    int index;

    heap = NULL;
    length = strlen(s);
    if (0 == length)
        return true;

    heap = (char*)malloc(length * sizeof(char));
    if (NULL == heap)
        exit(1);

    heap_ptr = heap;
    heap_tail = heap;

    for (index = 0; index < length; ++index)
    {
        int _f;
        char _c = s[index];
        if ('\0' == _c)
            break;

        switch (_c){
        case '(':
            *heap = 1;
            ++heap;
            break;

        case '[':
            *heap = 2;
            ++heap;
            break;

        case '{':
            *heap = 3;
            ++heap;
            break;

        case ')':
            if (heap == heap_tail)
                return false;

            --heap;

            _f = *heap;
            if (1 != _f)
                return false;
            break;

        case ']':
            if (heap == heap_tail)
                return false;

            --heap;

            _f = *heap;
            if (2 != _f)
                return false;
            break;
        
        case '}':
            if (heap == heap_tail)
                return false;

            --heap;

            _f = *heap;
            if (3 != _f)
                return false;
            break;
        }
    }

    if (heap != heap_tail)
        return false;

    return true;
}
