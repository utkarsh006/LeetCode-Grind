/* Problem :
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
*/


/* Approach :
1. Make a vector that has all 26 potential variations of morse code for each letter of the alphabet.
2. Go over the strings vector iteratively.
3. Create a set of all the words in the vector that have a morse equivalent.
4. The size of the set will depend on the particular morse code combination.

*/


class Solution
{
    public:
        int uniqueMorseRepresentations(vector<string>& words)
        {
            vector<string> t = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
            set<string> s;

            for(int i = 0; i < words.size();i++)
            {
                string tt = words[i];
                string temp = "";
                for(int j= 0 ;j < tt.length(); j++)
                {
                    int e = tt[j] - 'a';
                    temp += t[e];
                }
                s.insert(temp);
            }
            return s.size();
        }
};


/*
Time Complexity : O(S)
Space Complexity : O(S)
Where SS is the sum of the lengths of words in words. We iterate through each character of each word in words.
*/
