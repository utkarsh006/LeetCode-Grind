//  Repeated DNA Sequences..

/* Description:-
 The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 For example, "ACGAATTCCG" is a DNA sequence.When studying DNA, it is useful to identify repeated
  sequences within the DNA.Given a string s that represents a DNA sequence,return all the 
 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 You may return the answer in any order.
*/

/* Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]*/

/*Solution using - C++ || SLIDING WINDOW ON STRINGS ||*/

vector<string> findRepeatedDnaSequences(string s) {
        //this will store the final ans
        vector<string>v;
        //st and e->start and end of the 10 size string window
        int st=0,e=9;
        //this will map all tge 10 size strings 
        map<string,int>m;
        //this will store the 10 size string
        string t="";
        //extract first string of size 10
        for(int i=0;i<10;i++)
            t+=s[i];
        //then just shift this 10 size window and map all the 10 size string untill you reach at the last
        while(e<s.length())
        {
            //map the string in t(it is of size 10)
            m[t]++;
            //increase the start and end pointer inorder to shift the window of size 10
            e++;st++;
            //eliminate the first character of the string and add the next character to form the string of the new window
            t=t.substr(1)+s[e];
        }
        
        map<string,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            //if any of the value of string exceeds 1 then store those string
            if(itr->second>1)
                v.push_back(itr->first);
        }
        
        return v;
    }