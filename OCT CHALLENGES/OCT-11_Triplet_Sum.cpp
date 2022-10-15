class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min = INT_MAX, mid = min;

        for (int max : nums)
        {
            if (max < min)
            {
                min = max;
            }
            else if (max > min && max < mid)
            {
                mid = max;
            }
            else if (max > mid)
            {
                return 1;
            }
        }
        return 0;
    }
};