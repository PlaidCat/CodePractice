/*
 * https://leetcode.com/problems/valid-anagram
 *  
 * Code:   6:41
 *  CPU:    4ms (62.26%)
 *  MEM: 5.78MB (90.31%)
 * 
 */

bool isAnagram(char * s, char * t){
    // lower a is int:97
    int chars[26];
    int i = 0;
    for (i = 0; i < 26; ++i){
        chars[i] = 0;
    }
    i = 0;
    while (s[i] != '\0'){
        chars[s[i]-97] += 1;
        i += 1;
    }
    i = 0;
    while (t[i] != '\0'){
        chars[t[i]-97] -= 1;
        i += 1;
    }
    for (i = 0; i < 26; ++i){
        if (chars[i] != 0){
            return false;
        }
    }
    return true;
}