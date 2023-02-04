/*
Problem: Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
 where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 
*/

/*
Examples: 
            Example 1:

            Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
            Output: [1,2,2,3,5,6]
            Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
            The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
            Example 2:

            Input: nums1 = [1], m = 1, nums2 = [], n = 0
            Output: [1]
            Explanation: The arrays we are merging are [1] and [].
            The result of the merge is [1].
            Example 3:

            Input: nums1 = [0], m = 0, nums2 = [1], n = 1
            Output: [1]
            Explanation: The arrays we are merging are [] and [1].
            The result of the merge is [1].
            Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

/*
Approach: 

1. We will keep 3 pointers i=m-1(last index of nums1), j=n-1(last index of nums2), k=m+n-1 (total size of both arrays-1 )

2. Now since we are starting from last , we'll modify nums1 from the last index of nums1 . Will run while loop until i>=0 && j>=0

3. If the nums1[i]>numns2[j] then put nums1[i] in nums1[k] and decrement both i and k. Otherwise put put nums2[j] in nums1[k] and decrement both j and k.

4. Suppose our m=3 and n=3 so k =3+3-1 => k=5, so we'll compare the last index of both nums1 and nums2 and will check which one is greater , 
   then store the value of greater one in nums1[k]. It goes is descending order.

5. When any of i or j reaches 0 we will come out of while loop & will run another single while loop to check if index of i or j is greater 
   than 0 means elements are left to merge so we'll directly put them.
*/

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m-1;
        int j = n-1;
        int k = (m+n-1);
        
           while(i>=0 && j>=0)
           {
               if(nums1[i]>nums2[j])
                 nums1[k--] = nums1[i--];
               else
                   nums1[k--] = nums2[j--];
           }
        
           while(i>=0)
               nums1[k--]=nums1[i--];
          
           while(j>=0)
               nums1[k--]=nums2[j--];
        
    }

/*
Time Complexity:O(N)
Space Complexity:O(1)
*/