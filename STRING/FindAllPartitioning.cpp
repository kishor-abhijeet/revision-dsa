class Solution {
  public:
    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void backtrack(string &s, int idx ,vector<string> &curr,vector<vector<string>> &res){
        int n = s.length();
        if(idx == n){
            res.push_back(curr);
            return;
        }
        for(int i = idx; i<n; i++){
            if(isPalindrome(s,idx, i)){
                curr.push_back(s.substr(idx, i -idx+1));
                backtrack(s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>>res;
        vector<string>curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};
