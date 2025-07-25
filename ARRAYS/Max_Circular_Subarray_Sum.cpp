class Solution {
  public:
    int kadanesMax(vector<int> &arr , int n){
        int sum = arr[0];
        int maxSum = arr[0];
        for(int i =1; i<n; i++){
            sum = max(sum+arr[i], arr[i]);
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
    int kadanesMin(vector<int> &arr , int n){
        int sum = arr[0];
        int minSum = arr[0];
        for(int i =1; i<n; i++){
            sum = min(sum+arr[i], arr[i]);
            minSum = min(minSum , sum);
        }
        return minSum;
    }
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(begin(arr),end(arr),0);
        
        int max_subarr_sum = kadanesMax(arr,n);
        int min_subarr_sum = kadanesMin(arr,n);
        int cir_sum = sum - min_subarr_sum;
        if(max_subarr_sum > 0){
            return max(cir_sum , max_subarr_sum);
        }
        return max_subarr_sum;
    }
};
