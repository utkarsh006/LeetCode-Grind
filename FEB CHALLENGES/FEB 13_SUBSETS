//LEETCODE 78
class Solution 
{ public: vector<vector<int>> allsubsets; // STORING ALL SUBSETS
           
          void generate(vector<int>&subset, int i, vector<int>&nums)
          {   if(i==nums.size())                       // BASE CONDITION All elements are consumed
              { allsubsets.push_back(subset);
               return;
              }
                   
          //ith element not in subset
           generate(subset,i+1,nums);
       
         // ith element in subset
            subset.push_back(nums[i]);
            generate(subset,i+1,nums);
            subset.pop_back();
          
          }
 
          vector<vector<int>> subsets(vector<int>& nums) 
          { vector<int> empty;
            generate(empty,0,nums);
            return allsubsets;
        
          }
};
