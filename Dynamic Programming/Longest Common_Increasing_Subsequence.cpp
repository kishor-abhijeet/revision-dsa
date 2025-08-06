
class Solution {
  public:
    int LCIS(vector<int>& a, vector<int>& b) {
        // code here
        int m  = a.size(),
            n = b.size();
        vector<int>dp(n,0);
        for(int i =0; i<m; i++){
            int currLen = 0;
            for(int j =0; j<n; j++){
                if(a[i]==b[j]){
                    dp[j]=max(currLen+1, dp[j]);
                }
                else if(a[i]>b[j]){
                    currLen = max(currLen,dp[j]);
                }
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};
