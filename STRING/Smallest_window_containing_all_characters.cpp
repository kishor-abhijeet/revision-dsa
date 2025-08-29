class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        int n = s.length();
        if(p.length()> n) return "";
        unordered_map<char, int> mp;
        for(char &ch : p){
            mp[ch]++;
        }
        int reqCnt = p.length();
        int i =0, j= 0, minwindowSize = INT_MAX, start_i = 0;
        while(j<n){
            char ch = s[j];
            if(mp[ch]>0)
                reqCnt --;
            mp[ch]--;
            while(reqCnt == 0){
                int currWindowSize = j-i+1;
                if(minwindowSize > currWindowSize ){
                    minwindowSize = currWindowSize;
                    start_i = i;
                }            
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    reqCnt++;
                }
                i++;
            }
            j++;
        }
        return minwindowSize == INT_MAX ?  "":s.substr(start_i, minwindowSize);
    }
};
