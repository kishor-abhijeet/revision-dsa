/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check_mirror(Node *leftSub , Node *rightSub){
        if(leftSub == NULL && rightSub == NULL) return true;
        if(leftSub == NULL || rightSub == NULL || leftSub -> data != rightSub -> data) return false;
        return check_mirror(leftSub->left, rightSub->right)&&
                            check_mirror(leftSub->right, rightSub->left);
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root == NULL)return true;
        return check_mirror(root->left, root->right);
    }
};
