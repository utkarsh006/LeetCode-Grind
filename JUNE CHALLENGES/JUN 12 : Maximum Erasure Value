You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Algorithm:

- Create a sliding window: [nums[l], nums[l + 1], ..., num].
- For each number in the nums array, we check if this num is already present in the window. We can use a set to lookup in O(1).
- If the number is present in the window, we keep shrinking the window from the left until there's no repetition.
- We update the set by adding num and repeat the above process.

Example:
nums = [4,2,1,2,6]

1. Window: [4]; set = {4}; curr_sum = 4; max_sum = 4
2. Window: [4, 2]; set = {4, 2}; curr_sum = 6; max_sum = 6
3. Window: [4, 2, 1]; set = {4, 2, 1}; curr_sum = 7; max_sum = 7
4(a). Window: [2, 1, 2]; set = {2, 1}; curr_sum = 5; max_sum = 7
4(b). Window: [1, 2]; set = {1, 2}; curr_sum = 3; max_sum = 7
5. Window: [1, 2, 6]; set = {1, 2, 6}; curr_sum = 9; max_sum = 9

int maximumUniqueSubarray(vector<int>& nums)
    {
        unordered_set<int> seen;
        int currsum = 0, maxsum = 0, l = 0;
        
        for (int num : nums)
        {
            while (seen.find(num) != seen.end()) 
            {
                currsum -= nums[l];
                seen.erase(nums[l]);
                l += 1;
            }
            
            currsum += num;
            seen.insert(num);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
