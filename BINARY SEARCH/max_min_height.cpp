class Solution {
    private boolean isValid(int arr[], int l, int max, int days){
        int water[]=new int[arr.length];
        for(int i=0;i<arr.length;i++){
            if(i>0)
                water[i]=water[i-1];
                
            int curr=water[i]+arr[i];
            if(i>=l)
                curr-=water[i-l];
            
            if(curr<max){
                water[i]+=max-curr;
                days-=max-curr;
            }
            
            if(days<0)
                return false;
        }
        return true;
    }

    public int maxMinHeight(int[] arr, int k, int w) {
        // code here
        int n = arr.length;
        int hi = Integer.MAX_VALUE/4;
        int lo = 0;
        int res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(arr, w, mid, k)){
                lo=mid+1;
                res=(int)Math.max((int)mid, res);
            }
            else{
                hi=mid-1;
            }
        }
        return res;

    }
}
