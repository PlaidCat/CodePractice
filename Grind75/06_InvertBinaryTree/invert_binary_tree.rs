/* https://leetcode.com/problems/invert-binary-tree
*
* Code Time:  60m+ (all Rust Lang Issues)
*  Run Time:    0ms (100%)
*    Memory: 2.17MB (31.40%)
* 
* This problem is fundamentally easy, see C/C++/Python version in same
* directory as they had very short solve times.  This was a gap in my
* Rust experience making it challenging to know how to access the variables
* with their containers.  
* I did have to look at the disucssions for the "rust" way to accieve this.
* This will be annotated inline to help future me.
*/


// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    // RC are immutabel Smart Pointers, single threaded
    // RefCell is ability to do dynamic borrowing of the contained data type, single threaded ie no atomic operations
    // Multithreaded we'd need to use `sync` 
    //   RC -> ARC
    //   RefCell -> RwLock
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        //This is where I was getting hung up on using `Option` and Match and
        // needed to look up the mechanics of this:
        // https://stackoverflow.com/questions/72081657/rust-lang-what-is-if-let-somex-x-doing
        // Specificly this comment from Silvio Mayolo:
        // > In Rust, the right-hand side of a let is evaluated with the
        // > left-hand variable not in scope, so when the if let is evaluated,
        // > the outer x is still in-scope. Then, if it's a Some value, we
        // > make a new variable x which contains the inside of the Option.
        // > This variable shadows the previous x, making it inaccessible
        // > inside the if statement (in the same way that a function argument
        // > called x would render a global variable named x inaccessible by
        // > shadowing).
        // So I specifically started to rename the variables so its easier to
        // undertand the scope.
        // From the solution they used `try_borrow_mut` to pervenet panics this
        // make sense as we'll be diving until we run into a null leaf.
        if let Some(root2) = &root {;
          if let Ok(mut root3) = root2.try_borrow_mut() {
              let left = root3.left.clone();
              root3.left = Solution::invert_tree(root3.right.clone());
              root3.right = Solution::invert_tree(left);
          }
        }
        root
    }
}&