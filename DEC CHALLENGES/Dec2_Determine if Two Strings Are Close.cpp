class Solution {
public:
  
  /*   condition1 : we need the size of both strings to be same
       condition2 : we need freq of char in strings to be same, irrespective of the order
       if above 2 conditions are satisfied then just swapping will get us the word2 from word1
       Intuition: We just have to check for size and frequency     */
  
  
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size() != word2.size()) return false;

        set<char> st1,st2;
        vector<int> freq1(26,0), freq2(26,0);

           for(int i=0; i<word1.size(); i++)
           {
               st1.insert(word1[i]);
               st2.insert(word2[i]);

               freq1[word1[i] - 'a']++;
               freq2[word2[i] - 'a']++;
           }

            sort(freq1.begin(), freq1.end());
            sort(freq2.begin(), freq2.end());

          return (st1==st2 && freq1==freq2);
       
    }
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(26+26)
