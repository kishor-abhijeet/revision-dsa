class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int m = s.size();
        int len = 0;
        vector<int>lps(m,0);
        int i = 1;
        while(i<m){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                
                if(len!=0)
                    len = lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[m-1];
        
    }
};
