class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& G, int k) 
    {
        int m= G.size();
        int n= G[0].size();
        
        deque <int> tmp {};

        for(auto i=0; i<m; i++)
	        for(auto j=0; j<n; j++)
                tmp.push_back(G[i][j]);
    
        while(k--)
	    {
            int b= tmp.back();
            tmp.pop_back();
            tmp.push_front(b);
        }

        for(auto i=0; i<m; i++)
        {
	        for(auto j=0; j<n; j++)
	        { 
                G[i][j]= tmp.front();
                tmp.pop_front();
	        }
        }
        return G;
    }
};
