int func(string &s1, string &s2, int ind1, int ind2,vector<vector<int>> &dp)
{
    if(ind1<0 || ind2<0) return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2])
        return 1+func(s1, s2, ind1-1, ind2-1, dp);
    
    return dp[ind1][ind2] = 
        0 + max( func(s1, s2, ind1-1, ind2, dp), 
                 func(s1, s2, ind1, ind2-1, dp));
    
}
    int minDistance(string word1, string word2) 
    {  
        int n = word1.size();
        int m = word2.size();
    
       vector<vector<int>> dp(n, vector<int>(m,-1));
    
       return n+m - 2* func(word1, word2, n-1, m-1, dp);
    }
