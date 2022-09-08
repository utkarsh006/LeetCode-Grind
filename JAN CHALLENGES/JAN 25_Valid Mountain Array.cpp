/*  Problem : Valid Mountain Array

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example:
    Input: arr = [2,1]
    Output: false

    Input: arr = [0,3,2,1]
    Output: true

    Input: arr = [3,5,5]
    Output: false
*/

/*
Approach-1 (Using Binary Search)

-- Using Binary Search concept first we will find the mid of the array , the mid element will be greater than it's both left and right adjacent element.

-- For that we will check it in if condition if mid is greater than both adjacent then we will store mid in peak variable and will break out of while loop.

--If mid is not greater then we will shift left and right according to the value of mid adjacent's.

-- Once we found the peak we will run a for loop from i=0 to peak and will compare for strictly increasing if arr[i] < arr[i+1] , for loop will run until this condition becomes false or i reaches peak.

-- Other for loop will be from i=peak to n-1 and here we will compare for strictly decreasing if arr[i]>arr[i+1]
*/

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return false;
            /* we have initialized left =1 (not left=0) because if we reached to mid=0 then we will compare arr[mid] >arr[mid-1] which means arr[0]>arr[-1] that will become index out of bounds so we have taken left=1
            Similarly we have initialized right=n-2 (not right=n-1) because if we reached to mid=n-1 then we will compare arr[mid] >arr[mid+1] which means arr[n-1]>arr[n] that will become index out of bounds so we have taken right=n-2
            */
        int left = 1, right = n - 2, mid, peak = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // arr[mid] should be greater than its both adjacent values
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                peak = mid;
                break;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        if (peak == -1)
            return false;
        // once we got peak we will check from i=0 to peak for strictly increasing array
        for (int i = 0; i < peak; i++)
        {
            if (arr[i] >= arr[i + 1])
                return false;
        }
        // from i=peak to n-1 we will check for strictly decreasing array
        for (int i = peak; i < n - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                return false;
        }
        return true;
    }
};

/*
Time Complexity: O(LogN)
Space Complexity:O(1)
*/



/*
Approach-2  (Using two pointers)

-- Declare two pointers i and j and initialize them to start(0) and end(n-1) of the array.

-- Run a while loop for i along with checking the condition arr[i]<arr[i+1] , if this condition is true then we'll go inside while loop

-- If any elements in the array are equal then it will not be strictly increasing/decreasing so we'll return false.

-- If i==0 means i hasn't moved at all that means it is a decreasing array & there is no increment at beginning. Ex: [6,5,4,3,2,1]

--If i==n-1 that means i has reached till last element and the array is strictly increasing only. Ex: [1,2,3,4,5,6]

-- Same way we will run a while loop for j while checking the condition if it is smaller than its previous element arr[j-1]>arr[j].

-- If atlast i==j means there is a strict decrement and increment in the array so we'll return true.
*/

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        // condition given in ques length should be greater than equal to 3
        if (n < 3)
            return false;
        // pointers i and j at start position and end position
        int i = 0, j = n - 1;
        // i shall only move till n-2 because if it went to n-1 then index will go out of bounds for i+1
        while (i < n - 1 && arr[i] < arr[i + 1])
        {
            if (arr[i] == arr[i + 1])
                return false;
            else
                i++;
        }
        // if i==0 then there is no increment, if i==n-1 means there is no decrement.
        if (i == 0 || i == n - 1)
            return false;
        // j should be greater than 0 because if j becomes 0 then j-1 will go out of bounds
        while (j > 0 && arr[j - 1] > arr[j])
        {
            if (arr[j - 1] == arr[j])
                return false;
            else
                j--;
        }
        // it means they met in between and there is a strict increment and decrement
        if (i == j)
            return true;
        else
            return false;
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/