Decode Ways

//code

class Solution {
public:
    vector<int> dp;
    int decode(int m, int n,string s)
    {
        if(m >= n)
            return 1;
        
        if(dp[m] != -1)
        {
            return dp[m];
        }
        
        int num = 0;
        int count = 0;
        
        for(int i=m;i<n;i++)
        {
            num = num*10 + (s[i] - '0');
			
            if(num>=1 && num<=26)
            {
                count += decode(i+1,n,s);
            }
            else
            {
                break;
            }
        }
		
        dp[m] = count;
        return count;
    }
    int numDecodings(string s) {
        
         int n =s.length();
        
        for(int i=0;i<n;i++)
            dp.push_back(-1);
       
	   
        return decode(0,n,s);
    }
};
