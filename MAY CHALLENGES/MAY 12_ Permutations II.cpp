class Solution {
    vector<vector<int>> ans;
    
    void backtrack(vector<int>&nums,int x)
    {
        if(x==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        unordered_set<int>s;
        
        for(int i=x;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())continue;
            
            s.insert(nums[i]);
            swap(nums[i],nums[x]);
            
            backtrack(nums,x+1);
            swap(nums[i],nums[x]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        backtrack(nums,0);
        return ans;
    }
};
