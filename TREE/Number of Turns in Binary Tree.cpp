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

  
