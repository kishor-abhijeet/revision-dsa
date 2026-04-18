class Solution {
  public:
  int kadanes(vector<int> &temp) {
    
    // Stores the result (maximum sum found so far)
    int res = temp[0];           
    
    // Maximum sum of subarray ending at current position
    int maxEnding = temp[0];     

    for (int i = 1; i < temp.size(); i++) {
        
        // Either extend the previous subarray or start 
        // new from current element
        maxEnding = max(temp[i], maxEnding + temp[i]);

        // Update result if the new subarray sum is larger
        res = max(res, maxEnding);
    }
    return res;
}
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> temp = arr;
        int base = 0;
        for(int i: arr){
            if(i==1) base++;
        }
        for(int i=0; i<n; i++){
            if(temp[i]==1){
                temp[i]=-1;
            }
            else temp[i]=1;
        }
        int gain = kadanes(temp);
        if(gain<0) return base;
        return base+gain;
        
    }
};
