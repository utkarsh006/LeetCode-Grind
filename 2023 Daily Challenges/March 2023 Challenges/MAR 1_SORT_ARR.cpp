class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        multiset<int> se;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            se.insert(nums[i]);
        }
        for (auto it : se)
        {
            v.push_back(it);
        }
        return v;
    }
};