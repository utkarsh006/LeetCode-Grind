class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int currEnd = 0;
        int currFarth = 0;
        for (int i = 0; i < n - 1; i++)
        {
            currFarth = max(currFarth, i + nums[i]);
            if (i == currEnd)
            {
                ans++;
                currEnd = currFarth;
            }
        }
        return ans;
    }
};