class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        int dp[n+1][m+1];
        int res = 0;
        for(int i = 0; i<= n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i<= m; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                    
                }
                else
                    dp[i][j]=0;
                
            }
        }
        return res;
        
    }
};
