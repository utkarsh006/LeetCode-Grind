// Remove Duplicates from Sorted Array II

/* Problem Statement :
Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.
*/

/* Approach :
1. The main thing to note in this situation is that the array is sorted in a non-decreasing order.
2. When an element appears more than twice, we must replace it with the subsequent unique element.
3. Therefore, the fundamental action is to simply return the array's size if it is less than 3.
4. Now, if size is more than 2, we begin our traversal at index 2 and check to see if the value at index -2 is equal to or not.
5. If it is not equal, the current index value is added to it.
*/

class Solution
{
public:
    int removeDuplicates(vector<int>& arr)
    {
        int n = arr.size();
        // if size is less than 3 simply return n
        if(n < 3)
            return n;
        //upto two elements we don't have any problem
        int k = 2;
        // start traversing the array
        for(int i = 2; i < n; i++)
        {
            // if not equal we get our next unique element
            if(arr[i] != arr[k - 2])
            {
                // replace it
                arr[k] = arr[i];
                k++;
            }
        }
        return k;
    }
};

/* Time and Space Complexities :
Time Complexity --> O(n)
Space Complexity --> O(1)
*/
