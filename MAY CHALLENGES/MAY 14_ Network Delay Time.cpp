class Solution {
public:   // APPLY DIJSKTRA ALGO 
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>>graph(n+1);
        
        for(auto i : times)
            graph[i[0]].push_back ({i[1], i[2]});
        
        queue<int>q;
        q.push(k);
        vector<int>signal(n+1 , INT_MAX);
        signal[k] = 0;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            for(auto it  : graph[front])
            {
                int time  = it.second;
                int neighbour = it.first;
                int arrivalTime = signal[front] +  time;
                if(arrivalTime < signal[neighbour])
                {
                    signal[neighbour] = arrivalTime;
                    q.push(neighbour);
                }
            }
        }
        
        int maxi =INT_MIN;
        for(int i= 1;i<n+1; i++)
        {
            if(signal[i] == INT_MAX) return -1;
            maxi = max(maxi , signal[i]);
        }
        return maxi;
    }
};
