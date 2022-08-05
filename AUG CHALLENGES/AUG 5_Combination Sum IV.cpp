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
We may do this by keeping track of a dp array, where dp[i] represents the total number of potential possibilities when target = i.
All dp elements are initially initialized to -1, indicating that the number of combinations for each target has not yet been determined.
Once the number of combinations for subtarget = i (where 0<i<=target) has been computed,
it will be saved in dp[i] and will be returned immediately the next time a recursive call requests the same value rather than having to compute it again.
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
