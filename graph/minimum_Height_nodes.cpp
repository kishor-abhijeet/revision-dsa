class Solution {
  public:
    vector<int> minHeightRoot(int n, vector<vector<int>>& edges) {
        // Code here
        if(n==1) return {0};
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n);
       
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            inDegree[u]++;
            inDegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res;
        queue<int> q;
        for(int i=0; i<n ; i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }
        while( n > 2){
            int size = q.size();
            n -= size;
            while(size--){
                int u = q.front();
                q.pop();
                for(int &v: adj[u]){
                    inDegree[v]--;
                    if(inDegree[v]==1)
                        q.push(v);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};
