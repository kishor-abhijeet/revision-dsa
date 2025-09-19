/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        unordered_map<int, vector<int>> mp;
        int hd = 0;
        
        queue<pair<Node* , int>> q;
        q.push({root, 0});
        
        int mn = 0 , mx = 0;
        while(!q.empty()){
            pair<Node*,int> curr = q.front();
            q.pop();
            Node *node = curr.first;
            hd = curr.second;
            
            mp[hd].push_back(node->data);
            if(node->left){
                q.push({node->left, hd-1});
            }
            
            if(node->right){
                q.push({node->right, hd+1});
            }
            
            mn = min( mn, hd);
            mx = max( mx, hd);
        }
        vector<vector<int>>res;
        for(int i =mn; i<=mx; i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};
