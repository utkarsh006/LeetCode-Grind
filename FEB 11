// LEETCODE 567 : Permutations in string 
class Solution
{ public: bool checkInclusion(string s1, string s2)
          {  vector<int> x(26,0),y(26,0);
             int m=s1.length();
             int n=s2.length();
           
                  if(n<m)
                     return false;
           
                 for(int i=0;i<m;i++)
                 { y[s1[i]-'a']++;
                   x[s2[i]-'a']++;
                 }
           
                 for(int i=m;i<n;i++)
                 { if(x==y)
                     return true;
                       x[s2[i]-'a']++;
                       x[s2[i-m]-'a']--;
                 }
           
                 if(x==y)
                     return true;
                               return false;
         }
};
