## Problem Statement

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

### Example 1:

Input: s = "leetcode"

Output: 0

### Example 2:

Input: s = "loveleetcode"

Output: 2

### Example 3:

Input: s = "aabb"

Output: -1
 

## Constraints:

```


1 <= s.length <= 105
s consists of only lowercase English letters.


```


## Approach

- Store the frequency of each character in the map followed by traversal of the map and return the index of the character if frequency of the character is 1.

- If we have traversed the entire array and didn't got any character having frequency as 1,then return -1.




## Code 


```cpp


class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int>memo;
        
        //storing frequency of each characters of s
        for(auto current : s)
            memo[current]++;
        
        //traversing over s to get the first unique character
        for(int index = 0; index<s.size() ; index++)
        {
            char current = s[index];
            if(memo[current] == 1)
                return index;
        }
        return -1;
    }
};



```








**1. Time Complexity =O(n); Since in the worst case we will be traversing the entire string s of size n.**


**2. Space Complexity=O(n) ;Since in the worst case we will be getting an unordered map of size n, i.e. when all the elements will be unique.**
