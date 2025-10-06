APProach:-
  // Function NumberOfTurns(root, first, second):
  //   1. Find LCA of first and second.
  //   2. Initialize count = 0
  //   3. If LCA is first:
  //         Count turns from LCA (first) to second
  //      Else if LCA is second:
  //         Count turns from LCA (second) to first
  //      Else:
  //         Count turns from LCA->left to first (in left direction)
  //         Count turns from LCA->right to second (in right direction)
  //         Total = sum of both + 1   // for the turn at LCA
  //   4. Return total count

  
// CountTurn(LCA, Target_node, count, Turn)

// // if found the key value in tree 
// if (root->key == key)
//     return true;
// case 1: 
//    If Turn is true that means we are 
//       in left_subtree  
//    If we going left_subtree then there 
//       is no need to increment count 
//    else
//       Increment count and set turn as false  
// case 2:
//    if Turn is false that means we are in
//       right_subtree    
//    if we going right_subtree then there is
//       no need to increment count else
//    increment count and set turn as true.

// // if key is not found.
// return false;
 
