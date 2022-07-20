class Solution {
public:
    
    bool solution(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& dp)
    {
        
        if(s3.length() != s1.length()+s2.length())  
			return false;
        
        if(dp[i][j]!=-1)    
			return dp[i][j];
        
        if(i==s1.length() && j==s2.length() && k==s3.length())  
			return true;
        
        bool x=false, y=false;
        
        if(i!=s1.length())
        {
            if(s1[i]==s3[k])
                x = solution(s1, s2, s3, i+1, j, k+1, dp);                
        }
        
        if(j!=s2.length())
        {
            if(s2[j]==s3[k])
                y = solution(s1, s2, s3, i, j+1, k+1, dp);                
        }
        
        return dp[i][j] = x||y;;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        
        int a=s1.length(), b=s2.length();
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        
        return solution(s1,s2,s3,0,0,0,dp);
    }
};
