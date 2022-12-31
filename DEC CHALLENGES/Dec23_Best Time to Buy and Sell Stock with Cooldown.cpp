class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(idx >= prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit=0;
        
        if(buy)
        {
            int buy_stock = (-prices[idx] + solve(idx+1, 0, prices,dp));
            int skip_buying = (0 + solve(idx+1,1,prices,dp));
                
            profit = max(buy_stock,skip_buying);
        }
        
        else
        {
            int sell_stock = (prices[idx] + solve(idx+2, 1, prices,dp));
            int skip_selling = (0 + solve(idx+1,0,prices,dp));
                
            profit = max(sell_stock,skip_selling);
        }
        
        return dp[idx][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        // buy and idx are the two parameters changing
        vector<vector<int>> dp(n, vector<int>(2,-1));
        
        return solve(0,1,prices,dp);
    }
};
