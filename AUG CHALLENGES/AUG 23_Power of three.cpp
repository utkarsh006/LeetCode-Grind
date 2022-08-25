/* Problem : Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
*/

/*

Approach:

We need to check whether n is power of 3, so we divide it with until nis greater than 1, In between is it is not divisible by 3,
Then we directly return false.
If n<=1, then it is power of 3, only when n==1.

Algorithm:

1. Initialize an integer n.
2. Read the integer n.
3. If n is zero return false.
4. while n is not equal to 1
5. Do
6. if n%3 is not equal to 0 return false else true
7. n=n/3
8. print result

*/

class Solution {
public:
bool isPowerOfThree(int n) 
{

    if(n==0){
        return false;
    }
    
    while(n!=1){
        
        if(n%3!=0)
        {
            return false;
        }
        
        n=n/3;
        
    }
    
    return true;  
}
};

/* Tme Complexity O(n)
Space Complecity O(1)*/
