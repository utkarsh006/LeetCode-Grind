/* Problem :
Write a function that reverses a string.
The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

/* Solution 01 :
Here, the Two Pointer Approach is being used.
The swap function, which has an O(1) time complexity, will be used.
Move the pointer by using 2 pointers for the start and end.
*/

class Solution 
{
public:
    void reverseString(vector<char>& s)
    {  
        int n = s.size();
        int start=0,end=n-1;
        
        while(start<=end)
        {
           swap(s[start],s[end]);
           start++;
           end--;
        }
    }
};


/* Solution 02 :
Here, we're employing the O(n)-time-complex STL function reverse.
*/

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s.begin(), s.end());
        return;
    }
};

/*
Time complexity: O(n)
Space complexity: O(1)
*/
