
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Sorting will arrange your arrange so it will be easy to iterate
        sort(nums.begin(),nums.end());
	
        int sum=0,i=0;
        
        int ans=0,diff=INT_MAX;
        
        while(i<nums.size()){
        
        //having an start point and end point as two pointer
            int first=nums[i], s=i+1,e=nums.size()-1;
            while(s<e){
                
                if(first+nums[s]+nums[e]==target)
                    return target;
                    
            //comparing absolute difference which gives you closest answer		
                else if(abs(first+nums[s]+nums[e]-target)<diff)
                {   
                    diff=abs(first+nums[s]+nums[e]-target);
                    ans=first+nums[s]+nums[e];
                }
                if(first+nums[s]+nums[e]<target)
                    s++;
                else
                    e--;
                //tempAns=0;
                
            }
            i++;
        }
        return ans;
    }
};