/* Input: s = "abb"
Output: 2
Explanation: "abb" -> "bb" -> "". 
Remove palindromic subsequence "a" then "bb".  */


int removePalindromeSub(string s) 
    {
        if(s.size() == 0) return 0;
        
        int i = 0;
        int j = s.size()-1;
        
           while(i<j)
           {
               if(s[i]!=s[j]) return 2;
               i++;
               j--;
           }
        return 1;
    }
