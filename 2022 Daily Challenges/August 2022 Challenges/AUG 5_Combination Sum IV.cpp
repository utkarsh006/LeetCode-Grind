/* Problem :
Given an array of distinct integers nums and a target integer target,
return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.
*/

/* Approach - 1 (Brute Force)

Let's begin with the most fundamental strategy.
If the element at each index is smaller than the target,
we can always create a combination by choosing the current element.
*/

class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        if(target == 0) return 1;
        int ans = 0;
        for(auto& num : nums)
            if(num <= target) ans += combinationSum4(nums, target - num);
        return ans;
    }
};

/*
Time Complexity : O(N^T).
Space Complexity : O(T).
*/


/* Approach - 2 (memoization)

We repeatedly do the same computations for a target.
To avoid wasting time recalculating the amount of combinations obtained for a particular objective, this might be prevented by storing the information.
Our DP array (dp) will have cells (dp[i]) where i will stand for the remaining space left before T and dp[i] for the number of paths leading to the answer (dp[T]) from i.
We iterate over the various nums in our number array (N) as we build out dp, taking into account the cell that can be accessed with each num(dp[i-num]).
As a result, the value of dp[i] will equal the total of the outcomes of all of those potential moves.
To indicate the value of the finished combination, we must seed dp[0] with a value of 1. 
After the iteration is finished, we may then return dp[T] as the solution.

As an example,
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
dp[0] = 1 way
T[1] = dp[1]+dp[1-1] => 1 way

T[2]= dp[2] = > dp[2]+dp[2-1] = dp[2] +dp[1] ,
                dp[2] +dp[2-2] = dp[2] +dp[0] 
                                    ....... total  2 ways
                
T[3] = dp[3] => dp[3] +dp[3-1] = dp[3] +dp[2] ---- 2 ways
                dp[3] +dp[3-2] = dp[3] +dp[1]
                dp[3] +dp[3-3] = dp[3] +dp[0] 
                                    ........ total 4 ways
                
T[4] = dp[4] => dp[4] +dp[4-1] = dp[3] +dp[3] ---- 4 ways
                dp[4] +dp[4-2] = dp[3] +dp[2] ---- 2 ways
                dp[4] +dp[4-3] = dp[3] +dp[1] ........ 1 way
                                     ....... total 7 ways (output)
*/

class Solution
{
public:
    int combinationSum4(vector<int>& N, int T)
    {
        vector<unsigned int> dp(T+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= T; i++)
            for (int num : N)
                if (num <= i) dp[i] += dp[i-num];
        return dp[T];
    }
};

/*
Time Complexity : O(N*T).
Space Complexity : O(T).
*/


/* Approach - 3 (tabulation)

In our DP array (dp), the cells (dp[i]) reflect the number of ways we can get to i from the beginning point and
the current count as we move towards T, respectively (dp[0]).
Thus, dp[T] will serve as our ultimate answer.
We will cycle over the various nums in our number array (N) for each value of i as we build out dp,
updating the value of the cell that may be reached with each num (dp[i+num]) by adding the outcome of the current cell (dp[i]).
If the current cell is empty, we can go on without going through N iterations.
*/

class Solution
{
public:
    int combinationSum4(vector<int>& N, int T)
    {
        vector<unsigned int> dp(T+1, 0);
        dp[0] = 1;
        for (int i = 0; i < T; i++)
        {
            if (!dp[i]) continue;
            for (int num : N)
                if (num + i <= T) dp[i+num] += dp[i];
        }
        return dp[T];
    }
};

/*
Time Complexity : O(N*T).
Space Complexity : O(T).
*/
