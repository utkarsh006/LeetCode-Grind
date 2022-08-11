/* Problem Description
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel (‘a’, ‘e’, ‘i’, ‘o’, ‘u’)
Each vowel ‘a’ may only be followed by an ‘e’.
Each vowel ‘e’ may only be followed by an ‘a’ or an ‘i’.
Each vowel ‘i’ may not be followed by another ‘i’.
Each vowel ‘o’ may only be followed by an ‘i’ or a ‘u’.
Each vowel ‘u’ may only be followed by an ‘a’.
Since the answer may be too large, return it modulo 10^9 + 7.
*/


//Approach
/* 
We introduce the vector dp[1][i] ranging from 1 to 5 for all 5 vowels.
Then according to the question, we will add to dp[i][n], depending on the order how each vowel is being followed by the other vowel
for eg e may be followed by only a or an i, so and e being at index position 1, we write it as dp[i][n] which will be followed by the
elements at index position 1 and 2.
Hence we write it as dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
Similarly we do it for other vowels as well.
*/


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

//Time Complexity- O(n)
//Space Complexity-O(n)