class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        int min_cost = 0,
            max_cost = 0;
        sort(begin(prices),end(prices));
        int i =0,
            j=n-1;
        while(i<=j){
            min_cost +=prices[i];
            i++;
            j-=k;
        }
        
        i=n-1;
        j=0;
        while(i>=j){
            max_cost +=prices[i];
            i--;
            j+=k;
        }
        vector<int>res;
        res.push_back(min_cost);
        res.push_back(max_cost);
        return res;
    }
};
