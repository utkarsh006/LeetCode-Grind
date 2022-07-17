class Solution
{ public: int findMaxLength(vector& nums)
          { unordered_map <int,int> mymap;
                int sum = 0;
                int ls = 0;

           for(int i=0; i<nums.size(); i++)
           { sum += nums[i] == 0 ? -1: 1;
            
               if(sum==0)
               { if(ls < i+1)
                   ls= i+1;
               }
               
               else if (mymap.find(sum) != mymap.end())
               {
                   if(ls < i-mymap[sum])
                       ls = i-mymap[sum];
               }
               
               else
                   mymap[sum] = i;
           }
       return -1;
    
      }
};
