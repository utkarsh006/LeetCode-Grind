class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {   
        if(nums.size()==1) return 1;
        
        int peak=1, valley=1;
        
           for(int i=0; i<nums.size()-1; i++)
           {
               if(nums[i]>nums[i+1])
                   peak = valley+1;
               
               else if(nums[i]<nums[i+1])
                   valley = peak+1;    
                   
           }
        return max(valley,peak);
        
    }
};
