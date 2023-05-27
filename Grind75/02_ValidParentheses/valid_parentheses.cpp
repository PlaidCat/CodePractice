/*
 * https://leetcode.com/problems/valid-parentheses
 * 
 * RunTime   0ms (100%) 
 * Memory  6.3MB (51.90%)
 */

class Solution {
public:
    bool isValid(string s) {
        vector<char> open;
        for(int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                open.push_back(s[i]);
            }else if (open.size() > 0){
                if (s[i] ==')' && open.back() == '(')
                    open.pop_back();
                else if (s[i] == '}' && open.back() == '{')
                    open.pop_back();
                else if (s[i] == ']' && open.back() == '[')
                    open.pop_back();
                else
                    return false;
            }else{
                return false;
            }
        }

        if (open.size() > 0)
            return false;
        return true;
    }
};