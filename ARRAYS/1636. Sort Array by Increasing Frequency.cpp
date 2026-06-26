class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }
        vector<pair<int,int>> v(begin(mp), end(mp));
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for(auto it: v){
            for(int i=0; i<it.second; i++){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
//-------------EXPLANATION------------------------------
// What does cmp(a, b) actually mean?

// Your comparator is

// static bool cmp(pair<int,int> a, pair<int,int> b) {
//     if(a.second == b.second)
//         return a.first > b.first;

//     return a.second < b.second;
// }

// When sort() calls this function, it is asking only one question:

// "Should a come before b?"

// If the answer is

// true → put a before b
// false → put b before a

// That's all.

// It is not asking:

// Is a greater?
// Is a smaller?

// It simply asks:

// Should a be placed before b?
