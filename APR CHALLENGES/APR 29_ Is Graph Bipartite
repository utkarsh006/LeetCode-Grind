class Solution {
    
    void dfs(vector<vector<int>>& graph, int x, int color, unordered_map<int, 
              int>& colors, bool& ans)
    {
        if(!ans) return;
        if(colors.find(x) != colors.end())
        {
            if(colors[x] != color) 
                ans = false;
            
            return;
        }
        colors[x] = color;
        auto& children = graph[x];
        
        for(auto child : children) 
            dfs(graph, child, color^1, colors, ans);
           
        return;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        unordered_map<int, int> colors;
        bool ans = true;
        
        for(int i = 0; i < n; i++) 
        {
            if(colors.find(i) == colors.end())
            {
                dfs(graph, i, 0, colors, ans);
                if(!ans) return ans;
            }
        }
        
        return ans;
    }
};
