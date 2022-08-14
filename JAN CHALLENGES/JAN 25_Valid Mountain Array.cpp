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
Approach  (Using two pointers)

-- Declare two pointers i and j and initialize them to start(0) and end(n-1) of the array.

-- Run a while loop for i along with checking the condition arr[i]<arr[i+1] , if this condition is true then we'll go inside while loop 

-- If any elements in the array are equal then it will not be strictly increasing/decreasing so we'll return false.

-- If i==0 means i hasn't moved at all that means it is a decreasing array & there is no increment at beginning. Ex: [6,5,4,3,2,1]

--If i==n-1 that means i has reached till last element and the array is strictly increasing only. Ex: [1,2,3,4,5,6]

-- Same way we will run a while loop for j while checking the condition if it is smaller than its previous element arr[j-1]>arr[j].

-- If atlast i==j means there is a strict decrement and increment in the array so we'll return true.
*/


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        // condition given in ques length should be greater than equal to 3
        if(n<3) return false;
        // pointers i and j at start position and end position
        int i=0,j=n-1;
        // i shall only move till n-2 because if it went to n-1 then index will go out of bounds for i+1 
        while(i<n-1 && arr[i]<arr[i+1])
        {
            if(arr[i]==arr[i+1]) return false;
            else i++;
        }
        // if i==0 then there is no increment, if i==n-1 means there is no decrement.
        if(i==0 || i==n-1) return false;
        // j should be greater than 0 because if j becomes 0 then j-1 will go out of bounds
        while(j>0 && arr[j-1]>arr[j])
        {
            if(arr[j-1]==arr[j]) return false;
            else j--;
        }
        // it means they met in between and there is a strict increment and decrement
        if(i==j) return true;
        else return false;
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/