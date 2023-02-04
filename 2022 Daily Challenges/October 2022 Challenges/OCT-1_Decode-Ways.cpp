/* Problem:
Link to ps: https://leetcode.com/problems/decode-ways/
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

Approach


Starting from index 0 we can take 1 char or  2 char from current index depending on condition if we take 1 char that char should not be zero otherwise we return 0 because that is not valid encoding  and increment index to index++ if char is not zero 
if we take 2 char, number representaion of two char should be less than equal to 26 and increment index to index=index+2 if it is less than or equal to 26
Store the answer in dp table for current index (overlapping sub problems) shown in attached Image and return the answer obtain by taking 1 char at time + answer obtain by taking 2 char at time.*/


class Solution 
{
public:
    int recursion(int cur_ind,  string& str, int& len, vector<int>& dp)
    {
        
        // if we reach at index where value of char is zero
        if(cur_ind<=len-1 and str[cur_ind]=='0')
        {
            return dp[cur_ind]=0;
        }
        
        // if we reach last index or reach to string length
        if(cur_ind==len-1 or cur_ind==len)
        
        {
            return 1;
        }
        
        // if we already have an entry on dp table
        if(dp[cur_ind]!=0)
        {
            return dp[cur_ind];
        }
        
        // store the one and two char in integer form 
        int char1=str[cur_ind]-'0', char2=10*(str[cur_ind]-'0')+(str[cur_ind+1]-'0');
        
        // we can always take 1 char except when it is zero and for zero we already return from above code
        dp[cur_ind]=recursion(cur_ind+1, str, len, dp);
        
        // we can take two char if form interger value less than or equal to 26
        if(char2<=26)
        {
             // as answer always fits in a 32-bit integer so we dont have to take long long 
            dp[cur_ind]+=recursion(cur_ind+2, str, len, dp);
        }
        
        return dp[cur_ind];
    }
    
    int numDecodings(string s) 
    {
        
        // length of string
        int n=s.size();
        
        // declaring 1D dp table 
        vector<int>dp(n,0);
        
        return recursion(0,s,n,dp);
    }
};

/* Time complexity: O(n)
Space complexity: O(n) */