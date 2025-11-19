code:-
  class Solution {
  public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>dirs{{-1,0}, {1,0},{0,1}, {0,-1}};
    
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>res(m, vector<int>(n,INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        auto isSafe = [&](int x, int y){
            return x>=0 && x<m && y>=0 && y<n;//yaha par hum comparartor use kiye hain
            
        };
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();
            int x = cord.first;
            int y = cord.second;
            for(auto &dir: dirs){
                int x_ = x+dir[0];
                int y_ = y+dir[1];
                if(isSafe(x_,y_)){
                    int absDif = abs(mat[x][y]-mat[x_][y_]);
                    int maxDif = max(diff, absDif);
                    if(res[x_][y_]>maxDif){
                        res[x_][y_]= maxDif;
                        pq.push({maxDif, {x_,y_}});
                    }
                }
            }
        }
        return res[m-1][n-1];
        
    }
};
