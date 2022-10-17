// Count Subarrays With Fixed Bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(4, 0));
        // dp[i][0] up to i, min = mink, max = maxk, end at nums[i]
        // dp[i][1] up to i, min = mink, max < maxk, end at nums[i]
        // dp[i][2] up to i, min > mink, max = maxk, end at nums[i]
        // dp[i][3] up to i, min > mink, max < maxk, end at nums[i]
        for (int i = 1; i <= nums.size(); i++)
        {
            int val = nums[i-1];
            if (minK <= val && val <= maxK)
            {
                if (val == minK && val == maxK)
                {
                    dp[i][0] = dp[i-1][0] + 1;
                    dp[i][1] = 0;
                    dp[i][2] = 0;
                    dp[i][3] = 0;
                } else if (val == minK && val < maxK)
                {
                    dp[i][0] = dp[i-1][0] + dp[i-1][2];
                    dp[i][1] = dp[i-1][1] + dp[i-1][3] + 1;
                    dp[i][2] = 0;
                    dp[i][3] = 0;
                } else if (val > minK && val == maxK)
                {
                    dp[i][0] = dp[i-1][0] + dp[i-1][1];
                    dp[i][1] = 0;
                    dp[i][2] = dp[i-1][2] + dp[i-1][3] + 1;
                    dp[i][3] = 0;
                } else if (val > minK && val < maxK)
                {
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1];
                    dp[i][2] = dp[i-1][2];
                    dp[i][3] = dp[i-1][3] + 1;
                }
            }
        }
        long long res = 0;
        for (int i = 1; i <= nums.size(); i++)
            res += dp[i][0];
        return res;
    }
};