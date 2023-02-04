// 1155. Number of Dice Rolls With Target Sum
// link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

/*
1. Start from state N and Target
2. Check all base cases:
(i)   When target sum and number of dice simultaneously 0 return 1.
(ii)  When target sum 0  but number of dice not 0 return 0.
(iii) When target sum is !0 but number of dice becomes 0 return 0.
3. Check for precomputed answer if exist return from there.
4. Try all possible ways from i=1 to k where i<=target and stored the sum of all the possible ways of i in current state of DP n, target.
5. Finally return the answer for current state.

Time Complexity:
As we have N*Target different states and for each state we ran a loop for K times so, O(N*Target*K).

Space Complexity:
As we use 2d DP table of size N*Target so, O(N*Target).

*/

class Solution
{
public:
#define MOD 1000000007
    int dp[32][1002];

    int solve(int d, int f, int target)
    {
        if (d == 0 && target == 0)
            return 1;
        if (d <= 0 || target <= 0)
            return 0;
        if (dp[d][target] != -1)
            return dp[d][target];

        int sum = 0;
        for (int i = 1; i <= f; i++)
        {
            sum = (sum % MOD + solve(d - 1, f, target - i) % MOD) % MOD;
        }
        dp[d][target] = sum;
        return dp[d][target];
    }

    int numRollsToTarget(int d, int f, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(d, f, target);
    }
};
