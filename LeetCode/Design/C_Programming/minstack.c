/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *  Implement the MinStack class:
 * 
 *  MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack
 * 
 * Solution is:
 * Runtime: 24 ms (97.86% better)
 * Memory Usage: 13.2 MB (65.54% better)
 * 
 * https://leetcode.com/problems/min-stack/
 */


#include <stdlib.h>
#include <stdio.h>

typedef struct mylink {
  int val;
  int previous_min;
  struct mylink* back;
} mylink;

typedef struct {
  int cur_min;
  int size;
  mylink *stack;
} MinStack;


MinStack* minStackCreate() {
  MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
  stack->cur_min = 0;
  stack->size = 0;
  stack->stack = NULL;
  return stack;
}

void minStackPush(MinStack* obj, int val) {
  mylink *ele = (mylink*)malloc(sizeof(mylink));
  ele->val = val;
  ele->back = NULL;
  if (obj->stack == NULL){
    obj->cur_min = ele->val;
    ele->previous_min = ele->val;
  } else {
    if(ele->val < obj->stack->previous_min)
      ele->previous_min = ele->val;
    else
      ele->previous_min = obj->stack->previous_min;
    ele->back = obj->stack;
  }
  obj->stack = ele;
  obj->size += 1;
  obj->cur_min = ele->previous_min;
}

/*
size = 1 
*/

void minStackPop(MinStack* obj) {
  mylink *del = obj->stack;
  obj->stack = del->back;
  obj->size -= 1;
  if (obj->size > 0)
    obj->cur_min = obj->stack->previous_min;
  free(del);
}

int minStackTop(MinStack* obj) {
  return obj->stack->val;
}

int minStackGetMin(MinStack* obj) {
  return obj->cur_min;
}

void minStackFree(MinStack* obj) {
    mylink *del;
    while (obj->stack != NULL){
      del = obj->stack;
      obj->stack = del->back;
      free(del);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/