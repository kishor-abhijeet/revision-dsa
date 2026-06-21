class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
//---------------------------Counting sort----------------------
      //link:https://www.geeksforgeeks.org/dsa/counting-sort/
        int maxi = *max_element(begin(costs), end(costs));
        vector<int> cntArr(maxi+1,0);
        for(int ele : costs){
            cntArr[ele]++;
        }
        for(int i=1; i<cntArr.size(); i++){
            cntArr[i]=cntArr[i]+cntArr[i-1];

        }
        int n = costs.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            ans[cntArr[costs[i]] - 1] = costs[i];
            cntArr[costs[i]]--;
        }
//---------------------------------------------------------------------
        int total_icecream = 0;
        for(int cc: ans){
            if(cc> coins) break;
            total_icecream ++;
            coins = coins - cc;
        }
        
        return total_icecream;
    }
};
