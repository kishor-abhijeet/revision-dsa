//EXPLANATION OF THE COMPARATOR IS DISCUSSED BELOW


/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
struct CustomComparator {
    int target;
    CustomComparator(int t) : target(t) {}
    bool operator()(int a, int b) const {
        if(abs(target-a) != abs(target-b)){
            return abs(target-a) < abs(target-b);
        }
        return a<b;
    }
};

class Solution {
  public:
    void inorder(Node *root, vector<int> &vec){
        if(root == NULL) return;
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> vec;
        inorder(root, vec);
        sort(begin(vec), end(vec), CustomComparator(target));
        if(vec.size()>k){
            vec.resize(k);
        }
        return vec;
        
    }
};



//-------------LET'S UNDERSTAND THE CUSTOM COMPARATOR --------------------
CustomComparator(int t) : target(t) {}

This is a constructor that initializes the target member.

The syntax : target(t) is a member initializer list.

When you create an object like CustomComparator cmp(5);, it sets target = 5.
  //-----------------------
  bool operator()(int a, int b) const
means:

“This object can be called like a function with two integers (a and b), and it will return true or false, without modifying its internal state.”
