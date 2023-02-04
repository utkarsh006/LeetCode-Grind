## Problem Statement

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 
 ## Examples

#### Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]

Output: ["facebook","google","leetcode"]

#### Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]

Output: ["apple","google","leetcode"]


## Approach

1. MaxFreq -> it will store the max count of all the elements present in words1.

2. Initially maxFreq is empty.

3. Iterate over words2 to get curr2 , and create a temporary map(say temp) to store the count of all the elements of curr2.

4. Iterate over temp, and if the frequency of current character of temp is greater than the count of that character in maxFreq , then update its count in maxFreq.

5. Iterate over words1 to get curr1,and create a map(say m1) to store the frequency of characters of curr1.

6. Take a flag initially true.

7. Iterate over maxFreq, if count of current character in maxFreq is greater than the count of that charater in m1 ,then set the flag as false and break because it can't be a subset of curr1.

8. Now come out of the for loop and if the flag is true ,then it implies that the count of every characters in maxFreq is either less than or equal to the count of the characters in m1.

9. Finally push curr1 to ans and return ans.


## Code

```cpp


class Solution {
public:
    //words1 = ["leetcode"]
    //words2 = ["e","code","teec"]
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string>ans;
        
        unordered_map<char,int>maxFreq;
        for(auto curr2 : words2)
        {
            unordered_map<char,int>temp;
            for(auto i : curr2)
                temp[i]++;
            for(auto i : temp)
                maxFreq[i.first] = max(maxFreq[i.first],temp[i.first]);
        }
        
        for(auto curr1 : words1)
        {
            unordered_map<char,int>m1;
            for(auto i : curr1)
                m1[i]++;
            
            bool flag = true; 
            for(auto i : maxFreq)
            {
                if(maxFreq[i.first] > m1[i.first])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                ans.push_back(curr1);
        }
        return ans;
    }
};



```


#### Time Complexity = O(N)

#### Space Complexity = O(N)
