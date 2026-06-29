//Approach-1
class Solution {
public:
    bool isSubstring(string pt, string word){
        if(pt.length()>word.length()) return false;
        int i = 0;//pt
        int j = 0;//word
        int p = pt.length();
        int w = word.length();
        for(int i =0; i<=w-p; i++){
            int j =0;
            while(j<p && pt[j]==word[i+j]){
                j++;
            }
            if(p==j) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string pt: patterns){
            if(isSubstring(pt, word)) cnt++;
        }
        return cnt;
    }
};

//Approach-2
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (string &pt : patterns) {
            if (word.find(pt) != string::npos)
                cnt++;
        }

        return cnt;
    }
};
