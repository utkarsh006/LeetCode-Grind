/*
Problem :
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.

Algorithm:
1. Start with a range of 0 to nums.size() - 1.
It encompasses the entire vector from start to finish.
2. Narrow the interval to the lower half if the search key's value is smaller than the item in the interval's midpoint. 
do end = mid - 1.
3. If not, restrict it to the upper half.
do start equals mid + 1.
4. Check again and again until either the value is discovered or the interval is empty.
If not, return -1.
*/

class Solution 
{     
      public: int search(vector<int>& nums, int target) 
          { 
            int n=nums.size();
            int s=0;
            int e=n-1;
            while(s<=e)
             { 
                 int mid = s+(e-s)/2;
                 if(nums[mid]==target)
                     return mid;
                 else if(target<nums[mid])
                     e = mid-1;
                 else 
                     s = mid+1;
                 mid = s+(e-s)/2;
             }
         return -1;
          }
};

/*
Time Complexity : O(logN),
Space Complexity : O(1)
*/
