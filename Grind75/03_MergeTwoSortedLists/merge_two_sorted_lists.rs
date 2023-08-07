//
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/
// This was a lot of fighting rusts borrow checker, I ended up having to reference some discussion
// to figure out why I wasn't getting to do the things I thought I could do with rust as this example
// deviates from a lot of the ways linked lists are mentioned in google searches
//  
// Code:  49:19
//  CPU:    1ms (71.76%)
//  MEM: 2.04MB (57.65%)
//
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
  pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
      if list1.is_none(){
          return (list2)
      }
      if list2.is_none(){
          return (list1)
      }

      //This was a weird way of doing a pointer to the head.
      //We need to created a "pre node" that is invalid but its used to find the 
      //start of the list.
      let mut merged_head = ListNode::new(-1);
      let mut merged = &mut merged_head;

      //This was the trick was to clone he data into a mutable reference.
      let mut list1 = list1;
      let mut list2 = list2;

      while let (Some(node1), Some(node2)) = (&list1, &list2) {
          if node1.val < node2.val { 
              merged.next = list1.take();
              merged = merged.next.as_mut().unwrap();
              list1 = merged.next.take()
          } else {
              merged.next = list2.take();
              merged = merged.next.as_mut().unwrap();
              list2 = merged.next.take();
          }
      }

      //This did not like using is_none and needed to swithc to is_some()
      if list1.is_some(){
          merged.next = list1.take();
      }
      if list2.is_some(){
          merged.next = list2.take();
      }

      (merged_head.next)
  }
}