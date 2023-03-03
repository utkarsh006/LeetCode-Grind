class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        // ans vector to store the output
        vector<int> ans;
        // iterate all elements of array
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};