class Solution {
  public:
    static bool cmp(pair<int,int> &a , pair<int,int> &b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        
        unordered_map<int,int> mp;
        for(int i =0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> freq(mp.begin(), mp.end());
        sort(begin(freq), end(freq), cmp);
        vector<int> res;
        for(int i =0; i<k; i++){
            res.push_back(freq[i].first);
            
        }
        return res;
    }
};
