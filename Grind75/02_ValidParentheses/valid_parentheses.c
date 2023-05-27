/* 
 * https://leetcode.com/problems/valid-parentheses/
 * 
 *  Code Time ~6 min 
 *   Run Time    0ms (100.00%)
 * Memory Use  5.4MB ( 96.89%)
 */

bool isValid(char * s){
    int size = strlen(s);
    char *stack = (char*)malloc(sizeof(char)*size);
    int stack_size = 0;
    memset(stack, 0, size);
    
    int i;
    for(i = 0; i < size; ++i){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[stack_size] = s[i];
            stack_size++;
        } else if (stack_size > 0){
            if (s[i] == ')' && stack[stack_size-1] == '('){
                stack[stack_size -1] = 0;
                stack_size--;
            } else if (s[i] == '}' && stack[stack_size-1] == '{'){
                stack[stack_size - 1] = 0;
                stack_size--;
            } else if (s[i] == ']' && stack[stack_size-1] == '['){
                stack[stack_size - 1] = 0;
                stack_size--;
            } else {
                return false;
            }
        } else { 
            return false;
        }
    }
    if (stack_size > 0){
        return false;
    }
    return true;
}