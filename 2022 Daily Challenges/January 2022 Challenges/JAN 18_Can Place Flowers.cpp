/* Problem :
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's,
where 0 means empty and 1 means not empty, and an integer n, return
if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
*/


/* Approach :
1. Both of a flower's neighbors must be zeros in order for it to be planted at a zero.

2. As a result, we search the array for all such elements and set them to one.
    Count the number of flowers that were planted.

3. If ans >= n, we return true.
*/


/* Steps :
Set the number of flowers that can be planted in ans to 0 upon initialization.
A flowerbed's size, m, shall be used.
Use a for loop to go through the array:
1. Whether an element is 0, see if it is either at index 0 or if its neighbor to the left or before it is also 0.
    If not, see if it is at index m-1 or if its neighbor to the right is likewise 0.
    In that case, make the flowerbed[i] value 1 and increase ans.

2. If ans >= n, return true after iterating over the entire array.
*/


class Solution
{
public:
    bool canPlaceFlowers(vector<int>& fb, int n)
    {
        int m = fb.size(), ans=0;
        for(int i=0; i<m; i++)
        {
            if(fb[i]==0 && (i==0 || fb[i-1]!=1) && (i==m-1 || fb[i+1] != 1))
            {
                ans += 1;
                fb[i] = 1;
            }
        }
        return ans>=n ? true : false;
    }
};


/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
