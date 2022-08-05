/*
Porblem : ROTATE ARRAY
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/


/* NOTE: We can simply use two for loops and rotate the array with basic method but on leetcode it will give TLE
*/

/*
Approach 1 : Brute Force (Using Extra Space)

1. Make a vector temp to store the values

2. Our idea will be to store the last k values in temp array and then will push all the starting values in temp array

    ex: [1,2,3,4,5,6,7], k = 3

    here will store last k values which means 5,6,7 in array then all the starting values 1,2,3,4
    so output will be  5|6|7|1|2|3|4

3. Now assign this temp array to nums as nums will be automatically returned as answer.
*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp;
        /* if length of k is greater than nums then we can do modulo like if k=3 , n=2
        then k%n= 3%2 which will be 1 so that we can rotate it now
        */
        k=k%nums.size();
        int n=nums.size();
        // here storing last k values so count will be k means loop will work for k time that's why i=k
        for(int i=k;i>0;i--)
        {
            // we have nums[n-i] because we can directly take last values with it
            temp.push_back(nums[n-i]);
        }
        // storing the starting values from i=0 to i=n-k 
        for(int i=0;i<n-k;i++)
        {
            temp.push_back(nums[i]);
        }
        // assigning temp to nums as nums will be returned automatically
        nums=temp;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N) 
*/


/*
Approach 2 : Optimized 

1. Suppose we have this nums = [1,2,3,4,5,6,7], k = 3

2. First  we will reverse the whole array like this : 7,6,5,4,3,2,1
    Now if we divide this array into two parts and reverse these 2 parts then it will be come our ans

3.  7,6,5  | 4,3,2,1
    part1  | part2 

4. Now individually reverse both the array 
    so 5,6,7,1,2,3,4 will be the output
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1) return;
        k=k%nums.size();  

        // firstly reversed the whole array
        reverse(nums.begin(),nums.end());

        /* Now as we saw above we will divide it in 2 parts so first part we will rotate from starting to the k means k values will be rotated , and we know in this reverse process last value is exclusive so it will rotate till index =2  */
        reverse(nums.begin(),nums.begin()+k);

        // then we rotated elements beginning from k to last
        reverse(nums.begin()+k,nums.end());
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1) 
*/