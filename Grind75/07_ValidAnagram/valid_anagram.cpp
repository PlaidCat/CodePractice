/*
 * https://leetcode.com/problems/valid-anagram
 *  
 * Code:  <6:41
 *  CPU:    7ms (78.29%)
 *  MEM: 7.29MB (89.48%)
 * 
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {0};

        for( int i = 0; i < s.size(); i++){
            chars[s[i]-'a'] += 1;
        }
        for( int i = 0; i < t.size(); i++){
            chars[t[i]-'a'] -= 1;
        }
        for( int i = 0; i < 26; i++){
            if(chars[i] != 0){
                return false;
            }
        }
        return true;
    }
};