class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int median = nums[n/2];
        int steps=0;
        
        for(int i=0; i<n; i++)
        {
            steps += abs(nums[i]-median);
        }
        return steps;
            
    }
};

EFFICIENT

class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size();
    
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        
        int median = nums[n/2];
        int steps=0;
        
        for(int i=0; i<n; i++)
        {
            steps += abs(nums[i]-median);
        }
        return steps;
            
    }
};
