/* Problem :
You are given an integer array nums that is sorted in non-decreasing order.
Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:
Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.
A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements
without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

Example 1:

Input: nums = [1,2,3,3,4,5], Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5


Example 2:

Input: nums = [1,2,3,3,4,4,5,5], Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5


Example 3:

Input: nums = [1,2,3,4,4,5], Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
*/


/* Approach: (unordered map)

The number of subsequences that can begin at an element, end at it,
and have any number of subsequences in between determines the element's maximum frequency that can be accommodated.

How many subsequences can begin with element i : start = min(freq[i+1],freq[i+2]);

How many subsequences can finish at element i : end = min(freq[i-1],freq[i-2]);

The maximum number of subsequences between which i may intervene is given by : mid = min(freq[i+1]-start,freq[i-1]-end);

If the freq[i] is more than start+end+mid, we are unable to build the necessary subsequence and return false; otherwise, we return true.
*/


class Solution
{
    public:
        bool isPossible(vector<int>& nums)
        {
            unordered_map<int,int> freq;
            for(int i : nums)
            {
                freq[i]++;
            }

            for(auto& i:nums)
                {
                int ft = freq[i];
                int end = min(freq[i-1],freq[i-2]);
                int start = min(freq[i+1],freq[i+2]);
                ft = ft - end - start - min(freq[i+1]-start,freq[i-1]-end);
                if(ft>0)
                {
                    return false;
                }
            }
            return true;
        }
};

/*
Time Complexity : O(N)
Space Complexity : O(N)
*/
