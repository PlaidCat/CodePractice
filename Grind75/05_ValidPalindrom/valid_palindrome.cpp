/*
 * https://leetcode.com/problems/valid-palindrome
 *  
 * Code:  6:24
 *  CPU:    4ms (73.33%)
 *  MEM:  7.2MB (87.21%)
 * This was created several days after the C langauge version.  Apparently
 * it noodled around in my head a bit more and came up with a far less complex
 * version that doesn't require as many extra details.  I suspect we could
 * make this more efficient without using the isalnum or tolower but this will
 * work.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int strLen = s.size();
        if (strLen < 2)
            return true;
        
        int start = 0;
        int end = strLen - 1;

        while (start < end){
            if (!isalnum(s[start])){
                start++;
                continue;
            }
            if (!isalnum(s[end])){
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};