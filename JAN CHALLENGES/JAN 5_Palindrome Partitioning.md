## Palindrome Partitioning

## Problem Statement
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

## Example

- #### Example 1:

  Input: s = "aab"

  Output: [["a","a","b"],["aa","b"]]

- #### Example 2:

  Input: s = "a"

  Output: [["a"]]
  
  
 ## Intuition :- 
1. For a given string of length n we are having total n-1 possibilities , i.e. we can either make a cut after 0-th index,1-st index,2-nd index,.......upto n-1 index.

2. Now, we'll make a cut only when our left part is a pallindrome.

3. After making a cut check if its left part is a palindrome or not, if its a pindrome then add it to current answer and update the start index as i+1 
(where i is the index upto which we have considered as a valid palindrome).

4. Since we can have other possibilities too,therefore after making the recursive call backtrack by poping out the subtring entered in current answer.

5. If start >= s.size() , then this implies that we have proccessed one complete string hence we have got a valid combination so add it to answer and return.
 
 
 
 ## Code
 
 
 ```cpp
 
 
 class Solution {
public:
    
    //function to check if the current part of string is a palindrome or not
    bool isPalindrome(int start,int end,string left)
    {
        while(start<=end)
        {
            if(left[start] != left[end])
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    
    //function to find all possible palindrome partition
    void generatePartition(int start,int end,vector<string>& currAns,vector<vector<string>>& ans,string s)
    {
        //if start becomes greater than end
        //then it implies that we have got a valid combination
        //so push it into the answer
        if(start > end)
        {
            ans.push_back(currAns);
            return;
        }
        
        //iterate over the string starting from start position to find where to make a cut
        //such that the left part is a palindrome
        for(int i = start; i <=end ; i++)
        {
            //length of left part = i - start +1
            //we'll make an INTELLIGENT CUT
            //i.e. we'll make a cut only when the left part is a palindrome
            if(isPalindrome(start,i,s))
            {
                //if its a palindrome add it to currAns
                //and move ahead to find another palindromic part
                currAns.push_back(s.substr(start,i-start+1));
                generatePartition(i+1,end,currAns,ans,s);
                
                //we can have other possible answers too
                //therefore backtrack
                currAns.pop_back();
            }
        }
        
        return;
    }
    
    
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>>ans;//stores the final answer
        vector<string>currAns;//stores current answer
        int n = s.size();
        
        generatePartition(0,n-1,currAns,ans,s);
        
        return ans;
    }
};
 
 
 ```
 
 
 
 
- #### Time complexity = O(exponential)

- #### Space Complexity = O(N)
