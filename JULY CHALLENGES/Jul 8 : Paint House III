class Solution {
public:
    int infinity = 1e6+1;
    int dp[101][101][21] = {}; // memoization
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int last_clr) 
    {
        if(i >= houses.size() || target < 0)
            return target == 0 ? 0 : infinity;
        
        if(houses[i] != 0) // this house had been painted.
            return dfs(houses, cost, i+1, target - (last_clr != houses[i]), houses[i]);
        
        if(dp[i][target][last_clr])
            return dp[i][target][last_clr];
        
        int res = infinity;
        
  for(int clr = 1; clr <= cost[i].size(); ++clr) 
     res = min(res, cost[i][clr - 1] + dfs(houses, cost, i+1, target-(last_clr != clr), clr));
        
        return dp[i][target][last_clr] = res;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        int res = dfs(houses, cost, 0, target, 0);
        return res > 1e6 ? -1 : res;
    }
};
