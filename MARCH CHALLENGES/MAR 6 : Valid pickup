// n orders there will be 2n places for arranging pickup & delivery.
class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) 
    { long places = 2*n;
      long seq = 1;
        
         for(int i=n;i>=1;i--)
         {
             seq = (seq*(places*(places-1))/2) % mod;
             places = places-2;
         }
     return (int)seq;
        
    }
};  // leetcode 1359
