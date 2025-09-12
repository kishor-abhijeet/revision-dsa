// APPROACH:-
//   Recursively traverse

//   i) If either of left subtree or right subtree is not SingleValued, the current_subtree is also not SingleValued.

//   ii) If root->left and root->right are null then the subtree is SingleValued.

//   iii) If root->left exists and root->left->data != root->data then the subtree is not SingleValued.

//   iv) If root->right exists and root->right->data != root->data then the subtree is not singleValued.

//    vi) Else it is a singleValued subtree, hence increment count.

// 5. Return count.

// 6. Try to implement it using above points. Later, take a look at the code below.
// -------------------------CODE -----------------------------------THIS QUESTION AVAILABLE ON GFG ----------------------------------------
class Solution {
  public:
    bool solve(Node *root, int &ans){
        
        if(root == NULL) return true;
        bool lefts = solve(root->left, ans);
        bool rights = solve(root->right , ans);
        
        if(lefts && rights){
            if(root->left != NULL && root->left->data != root->data) return false;
            if(root->right != NULL && root->right->data != root->data) return false;
            ans++;
            return true;
        }
        return false;
    }
    int singlevalued(Node *root) {
        // code here
        int ans = 0;
        solve(root, ans);
        return ans;
        
    }
};
