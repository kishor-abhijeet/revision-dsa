
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        
        unordered_map<char ,int> freq;
        for(char ch: text){
            freq[ch]++;
        }
        
        if(freq['l'] <2 || freq['o']<2) return 0;
        int ans = INT_MAX;
        for(char ch: target){
           ans = min(ans, freq[ch]);
        }
        int temp = min(freq['o'], freq['l']);
        temp = temp/2;
        if(ans > temp) return temp;
        return ans;
    }
};
