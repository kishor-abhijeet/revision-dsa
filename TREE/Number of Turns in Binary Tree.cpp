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

  // function count number of turn need to reach
// given node from it's LCA we have two way to
bool CountTurn(Node* root, int key, bool turn,
                                   int* count)
{
    if (root == NULL)
        return false;

    // if found the key value in tree
    if (root->key == key)
        return true;

    // Case 1:
    if (turn == true) {
        if (CountTurn(root->left, key, turn, count))
            return true;
        if (CountTurn(root->right, key, !turn, count)) {
            *count += 1;
            return true;
        }
    } 
    else // Case 2:
    {
        if (CountTurn(root->right, key, turn, count))
            return true;
        if (CountTurn(root->left, key, !turn, count)) {
            *count += 1;
            return true;
        }
    }
    return false;
}
 // Function to find nodes common to given two nodes
int NumberOFTurn(struct Node* root, int first, 
                                   int second)
{
    struct Node* LCA = findLCA(root, first, second);

    // there is no path between these two node
    if (LCA == NULL)
        return -1;
    int Count = 0;

    // case 1:
    if (LCA->key != first && LCA->key != second) {
        
        // count number of turns needs to reached
        // the second node from LCA
        if (CountTurn(LCA->right, second, false,
                                           &Count)
            || CountTurn(LCA->left, second, true, 
                                           &Count))
            ;
        
        // count number of turns needs to reached 
        // the first node from LCA
        if (CountTurn(LCA->left, first, true, 
                                       &Count)
            || CountTurn(LCA->right, first, false, 
                                       &Count))
            ;
        return Count + 1;
    }

    // case 2:
    if (LCA->key == first) {

        // count number of turns needs to reached 
        // the second node from LCA
        CountTurn(LCA->right, second, false, &Count);
        CountTurn(LCA->left, second, true, &Count);
        return Count;
    } else {

        // count number of turns needs to reached
        // the first node from LCA1
        CountTurn(LCA->right, first, false, &Count);
        CountTurn(LCA->left, first, true, &Count);
        return Count;
    }
}

