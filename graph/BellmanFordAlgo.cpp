vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>result(V, 1e8);
        result[src]=0;
        for(int count = 1; count<=V-1; count++)
        {
            for(auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(result[u]!=1e8 && result[u]+wt < result[v])
                {
                    result[v]= result[u]+wt;
                }
            }
        }
        //Now detect cycle(if it is negative cycle then return -1)
        for(auto &edge : edges)
        {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(result[u]!=1e8&& result[u]+wt < result[v])
                {
                    return{-1};//return vector by filling -1 in it
                }
        }
        return result;
        
    }
