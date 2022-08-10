class Solution {
public:
    int countVowelPermutation(int n) {
       vector<vector<int64_t>> dp(n + 1, vector<int64_t>(5, 0));
        for (int i = 0; i < 5; ++ i) {
            dp[1][i] = 1;
        }
        const int MOD = 1000000007;
        for (int i = 2; i <= n; ++ i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] +dp[i - 1][4]) % MOD; 
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];                                 
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;                                            
        }
        return (dp.back()[0] + 
            dp.back()[1] +
            dp.back()[2] +
            dp.back()[3] +
            dp.back()[4]) % MOD;          
    }
};