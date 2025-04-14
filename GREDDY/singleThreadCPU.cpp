class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
//creating vector for numbering each interval of tasks
        vector<array<int, 3>>sortedTasks;
        for(int i =0; i<n; i++){
            int startTime = tasks[i][0];
            int processingTime = tasks[i][1];
            sortedTasks.push_back({startTime,processingTime,i});
        }
//sorting
        sort(begin(sortedTasks),end(sortedTasks));
        vector<int>res;
        long long currTime = 0;
        int idx =0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        while(idx<n || !pq.empty()){
            if(pq.empty() && currTime < sortedTasks[idx][0]){
                currTime = sortedTasks[idx][0];
            }
            while(idx <n && sortedTasks[idx][0] <= currTime)
            {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }
            pair<int, int>tempTask = pq.top();
            pq.pop();
            currTime += tempTask.first;
            res.push_back(tempTask.second);
        }
        return res;
    }
};
