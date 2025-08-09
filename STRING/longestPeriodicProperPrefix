//link : "https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1"
class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size();
        
        int len = n-1;
        while(len){
            int i =0;
            int prefix_len=len;
            while(prefix_len<n){
                if(s[i]==s[prefix_len]){
                    i++;
                    prefix_len++;
                }
                else
                    break;
                
            }
            if(prefix_len == n)
                return len;
            len--;
        }
        return -1;
    }
};
