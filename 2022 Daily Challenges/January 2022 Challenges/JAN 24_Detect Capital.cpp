/* Problem: We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example:

        Example 1:

        Input: word = "USA"
        Output: true

        Example 2:

        Input: word = "FlaG"
        Output: false

*/


/*
Approach-1 

--In first if we are checking for all the capital letters , if the starting 2 letters are capital then all others have to be same Ex: USA 

--Second condition is for all the words who should have all letters small ,first letter can be small or cannnot be Ex: leetcode, Google
*/



class Solution {
public:
    bool detectCapitalUse(string word) {

        // condition is for all the capital letters because index =0,1 are capital Ex:USA
        if(word[0] >='A' && word[0]<='Z' && word[1] >='A' && word[1]<='Z')
        {
            for(int i=2;i<word.size();i++)
            {
                // if any letter is small then it's not the right word hence return false
                if(word[i]>='a' && word[i]<='z') return false;
            }
        }
        else
        {
            // here first letter(index=0) can be capital or small Ex:leetcode, Google
            for(int i=1;i<word.size();i++)
            {
                // but from second letter(index=1) it has to be small , if it's capital then we'll return false
                if(word[i] >='A' && word[i]<='Z') return false;
            }
        }
        return true;
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/

/*
Approach-2

-- Here we have use 2 variables count (for counting the capital letters in the word) , loc (for storing the location of capital letter)
-- We will traverse the whole word and will increase the count if the letter is capital and will store the index of capital letter in loc
-- Once we are out of loop
        1. if count will be equal to word length it means all letters are capital like "USA" so it is right word
        2. if count==0 that means there are no capital letters & all letters are small like "leetcode" so it is     right word
        3. if count==1 and loc=0 means on 0th index we got the first capital letter , rest all letter are small like Google so it is right word
        4. Except these all are wrong word so return false;
*/


class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0,loc=-1;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                count++;
                loc=i;
            }
        }
        // any of the condition is true it means it's a right word
        if(count==word.size() || count==0 || (count==1 && loc==0)) return true;
        return false;
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/