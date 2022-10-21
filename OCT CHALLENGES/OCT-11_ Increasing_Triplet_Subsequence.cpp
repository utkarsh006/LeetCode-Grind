// Explanation:
/*
Brute Force Approch: In this approch we will simply run tree loop and check each element one by one
    Time-Complexity : O(n^3)

Optimized Solution:
In the optimized solution we will mantaing two variables i,j
1) i and j is intilized with MAX value
2) we will iterate through the array and whenever we found nums[in]<i we will update  i=nums[in]
3) and if when we found nums[j]<j we will update j=nums[in]
4) we don't have to maintain variable k as whenever we find the 3rd element we will simply return true
5) if we can't find any of such index then we return false;
NOTE: if size of array<3 then we return false;

TIME-Complexity: O(n)
Space-Complexity: O(1)
*/

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int i = INT_MAX, j = INT_MAX;
        if (nums.size() < 3)
            return false;
        for (int in = 0; in < nums.size(); in++)
        {
            if (nums[in] <= i)
                i = nums[in];
            else if (nums[in] <= j)
                j = nums[in];
            else
                return true;
        }
        return false;
    }
};