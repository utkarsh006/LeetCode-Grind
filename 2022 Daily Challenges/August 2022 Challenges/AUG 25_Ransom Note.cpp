/*
Problem: Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the
letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example:
        Example 1:
            Input: ransomNote = "a", magazine = "b"
            Output: false

        Example 2:
            Input: ransomNote = "aa", magazine = "ab"
            Output: false

        Example 3:
            Input: ransomNote = "aa", magazine = "aab"
            Output: true
*/

/*
Approach-1 Using Hashmap

1. We will use Hashmap to store the characters and since we can store only lower case alphabets so maximum 
we'll store 26 alphabets.

2. Edge Case: If size of string magazine is less than size of string ransomNote then we will return false 
because then it's not possible to make ransomNote from magazine.

3. Firstly we'll run a for loop for string magazine and will store it's characters in hashmap along with their frequency.

4. Once that's done, we'll run another for loop for ransomNote string to check if the characters of ransomNote 
exist in map or not, so if the count of characters of ransomNote string is greater than 0 that means it exist so 
we'll decrement the frequency in map of that character otherwise we will return false(means char doesn't exist in map).

5. Atlast we'll return true, so if we didn't return any false from above then it means we can make ransomNote string from magazine string 
hence it will return true.
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int n = ransomNote.size(), m = magazine.size();
        if (n > m)
            return false;
        unordered_map<char, int> mp(26);
        for (int i = 0; i < m; i++)
        {
            mp[magazine[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[ransomNote[i]] <= 0)
            {
                return false;
            }
            mp[ransomNote[i]]--;
        }
        return true;
    }
};

/*
Time Complexity:O(M+N)
Space Complexity:O(1)  maximum we will store 26 characters in map
*/

/*
Approach-2  Using Vector

1. Logic is same, we'll use vector instead of hashmap and we'll declare 26 size vector because maximum characters are 26 
(so we have total 26 places in vector, one place for every char).

2. Now we will store the frquency of characters of magazine in vector , so v[magazine[i]-'a']
 this means that we will subtract the ASCII value of character from 'a', 
so if char is b then ASCII of b is 98 and of a is 97 then v['b''-'a'] which will be v[98-97] 
which means v[1] so in v[1] which is the place of b we will increment the frequency as 1.

3. Same way we'll update all frequencies in the vector. Now we'll run a for loop for ransomNote string and will check for it's frequency.

4. If frequency of characters of ransomNote is greater than 0 then we'll decrement it by 1 otherwise we'll return false.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size(),m=magazine.size();
        if(n>m) return false;
        vector<int>v(26);
        for(int i=0;i<m;i++)
        {
            v[magazine[i]-'a']++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(v[ransomNote[i]-'a']>0)
            {
                v[ransomNote[i]-'a']--;
            }
            else return false;
        }
        return true;
    }
};

/*
Time Complexity:O(M+N)
Space Complexity:O(1)  maximum we will store 26 characters in map
*/