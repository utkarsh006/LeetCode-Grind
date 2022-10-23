Question : A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise

Approach :
Since no repetition is allowed so we can put all the characters of the string in the set .
If the set size is 26 then only it is a valid string otherwise not.
  
  
Soution:
class Solution {
public:
    
    bool checkIfPangram(string sentence) {
    unordered_set<char> st (sentence.begin(), sentence.end());     
    return st.size()==26;                                         
}
    
};

  
