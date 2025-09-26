// C++ program to find LCA using Single traversal
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *findLca(Node *root, int n1, int n2){
        if(!root) return NULL;
        
        if(root->data == n1 || root->data==n2){
            return root;
        }
        
        Node *leftLca = findLca(root->left, n1, n2);
        Node *rightLca = findLca(root->right, n1, n2);
        
        if( leftLca && rightLca )
            return root;
        return  leftLca ? leftLca : rightLca;
    }
    
    int findLevel(Node *lca, int key , int level){
        if(lca == NULL) return -1;
        
        int left = findLevel(lca->left, key, level+1);
        
        if(lca->data == key)
            return level;
        
        if(left ==-1){
            return findLevel(lca->right, key, level+1);
            
        }
        return left;
    }
    
    int findDist(Node* root, int n1, int n2) {
        // Your code here
        Node *lca = findLca(root, n1, n2);
        
        int d1 = findLevel(lca , n1, 0);
        int d2 = findLevel(lca , n2, 0);
        
        return d1+d2;
    }
};
