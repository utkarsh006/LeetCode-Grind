// 1578. Minimum Time to Make Rope Colorful
// link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

/*
Approach:
1. Create a DP Array of length n(size colors string).
2. Write a recursive function to traverse the colors string in reverse order (important parameters: prevMinTime, prevColor, dp).
3. Add base to check if we are getting out of bounds and return 0 from there.
4. Check if DP at current index is -1 or not, if not return the curretn value.
5. If previous color and current color of ballon is not same then call our funtion with next index(index-1) and update the other values too i.e prevMinTime, prevColor
6. Otherwise, keep index parameter same as index-1 but for prevMinTime make it maximum(prevMinTime, current neededTime) and add new time to our answer that is minimum(prevMinTime, current neededTime).
7. Store the answer in the DP array and return it.

Time complexity:
O(n)

Space complexity:
O(n)
*/

class Solution
{
public:
    int rf(int index, string &colors, vector<int> &neededTime, vector<int> &dp, char prevColor, int prevMinTime)
    {
        int step=0, step2=0;
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        if(prevColor != colors[index])
            step = rf(index-1, colors, neededTime, dp, colors[index], neededTime[index]);
        else
            step = rf(index-1, colors, neededTime, dp, colors[index], max(neededTime[index], prevMinTime)) + min(neededTime[index], prevMinTime);
        return dp[index] = step;
    }

    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size();
        vector<int> dp(n, -1);
        return rf(n-1, colors, neededTime, dp, 'A', 0);
    }
};


