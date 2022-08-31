/*
Problem : Non-decreasing Array
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
*/

/*
Example:
        Example 1:
        Input: nums = [4,2,3]
        Output: true
        Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

        Example 2:
        Input: nums = [4,2,1]
        Output: false
        Explanation: You cannot get a non-decreasing array by modifying at most one element.

*/

/*
Approach:

1. We want our array to be an increasing array and for that we can modify maximum one element.

2. Basic thought can be that if we keep run a for loop from 0->n-1 and keep checking if nums[i]>nums[i+1] and increment the count whenever this condition is true, 
   if count is greater than 1 then we'll return false.

3. But in this question we have been told to modify the input , so simultaneously we'll modify the input maximum one time to make the array as increasing array. 
   Though if our counnt is more than 1 then we'll return false.

4. If nums[i]>nums[i+1] then we'll also check that if i>0(means i shoudln't be index=0) and  
   nums[i-1]>nums[i+1] then we'll modify the nums[i+1] as nums[i] so that we can make it increasing array.

5. Else we'll store nums[i]=nums[i+1] , for making it increasing we'll look for the neighbour elements of i.

6. Atlast we'll return true means we didn't got return false from above and it's an increasing array.
*/

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                count++;
                if (count > 1)
                    return 0;
                if (i > 0 && nums[i - 1] > nums[i + 1])
                {
                    nums[i + 1] = nums[i];
                }
                else
                    nums[i] = nums[i + 1];
            }
        }
        return 1;
    }
};

/*
Time  Complexity:O(N)
Space Complexity:O(1)
*/