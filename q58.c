/*
 * Problem #58
 * https://leetcode.com/problems/length-of-last-word/
 */

int lengthOfLastWord(char * s){
    if (NULL == s) {
        return 0;
    }
    
    int siz = strlen(s);
    if (0 == siz) {
        return 0;
    }
    
    int last_word = 0;
    int word = 0;
    int i = 0;
    char c = s[i];
    
    while ('\0' != c) {
        if (' ' == c) {
            if (0 != word) {
                last_word = word;
            }
            word = 0;
        } else {
            word += 1;
        }
        
        i += 1;
        c = s[i];
    }
    
    if (0 != word) {
        last_word = word;
    }
    
    return last_word;
}

