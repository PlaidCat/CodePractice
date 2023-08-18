/*
 * https://leetcode.com/problems/valid-palindrome
 *  
 * Code:  40:26
 *  CPU:    2ms (77.96%)
 *  MEM: 6.28MB (66.03%)
 * This one was good that added a bunch of extra gotchas. and make you skip
 * random non-alphaNumeric entries.  While its still not very hard its took
 * me a second to readjust to the walking the two "pointers" at from each
 * end.
 */


//  1 is for forward (start)
// -1 is for reverse (end)
int findNextAlphaNumeric(char *s, int pos, int direction, int limit){
    //while (isAlphaNumeric(s[pos]) != true &&  pos != limit){
    
    while ((isalnum(s[pos]) == false)){
        pos += direction;
        if (pos == limit)
            return pos;
    }
    return pos;
}

bool isPalindrome(char * s){
    int start = 0;
    int end  = 0;
    int size = 0;
    while (s[size] != '\0'){
        size += 1;
    }
    if (size < 2)
        return true;

    end = size - 1 ; // this will be our itterator, we don't want to start comparing with the null terminator
    start = findNextAlphaNumeric(s, start, 1, size);
    end = findNextAlphaNumeric(s, end, -1, 0);

    while (start < end){
        if (tolower(s[start]) != tolower(s[end]))
            return false;
        start = findNextAlphaNumeric(s, start+1, 1, size);
        end = findNextAlphaNumeric(s, end-1, -1, 0);
    }
    return true;
}