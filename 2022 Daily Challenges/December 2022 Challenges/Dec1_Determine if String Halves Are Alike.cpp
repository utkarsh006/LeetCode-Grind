class Solution {
public:
  
    // We follow a simple binary search like approach, search for vowels and first half of the array from start to mid and then from mid+1 to the end position.
   // Basically, mid=(start+end)/2 so, start will be the 0 index and end will be the last index.
  //  Increment the vowelcount in both halves of the string and compare them finally. If it comes out to be equal return true else return false.
  
    bool halvesAreAlike(string s)
    {
        int n=s.size();
        int mid = (0 + n-1)/2;
        int count1=0, count2=0;
    
         for(int i=0;i<=mid;i++)
         {
           if(s[i]=='a'|| s[i]=='e'|| s[i]== 'i'|| s[i]== 'o'|| s[i]=='u'|| 
              s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')

                      count1++;
         }
    
         for(int i=mid+1;i<s.size();i++)
         {
           if(s[i]=='a'|| s[i]=='e'||s[i]== 'i'||s[i]== 'o'||s[i]== 'u'||
              s[i]== 'A'||s[i]== 'E'||s[i]== 'I'||s[i]== 'O'|| s[i]=='U')
                  count2++;
         }
    
       return (count1==count2);
        
    }
    
};

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)
