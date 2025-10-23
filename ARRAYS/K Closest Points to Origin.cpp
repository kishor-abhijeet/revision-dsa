class Solution {
  public:
    int calDist(vector<int>& p){
        return  p[0]*p[0] + p[1]*p[1];
        
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        int n = points.size();
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for(int i = 0; i<n; i++){
            int dist = (calDist(points[i]));
            if(maxHeap.size()< k ){
                maxHeap.push({dist, points[i]});
            }
            else{
                if(dist < maxHeap.top().first){
                    maxHeap.pop();
                    maxHeap.push({dist, points[i]});
                }
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
