class Solution {
  public:
    bool check(int mid, vector<int>& arr, int k){
        int n = arr.size();
        int cnt = 0;
        int sum = 0;
        for(int i =0; i<n; i++){
            if(arr[i]> mid) return false;
            sum += arr[i];
            if(sum > mid){
                cnt++;
                sum = arr[i];
            }
        }
        cnt++;
        if(cnt <= k) return true;
        return false;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int lo = *max_element(begin(arr), end(arr));
        int hi = 0;
        for(int i =0; i<n; i++){
            hi += arr[i];
            
        }
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi -lo)/2;
            if(check(mid, arr, k)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};
