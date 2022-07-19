class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        stack<int> s;   vector<int>a;
        reverse(nums.begin(),nums.end());
        
        for(auto x:nums)
        {
            while(!s.empty() and x>s.top())
            { 
                a.push_back(s.top());
                s.pop();
            }
            s.push(x);
        }
        
        while(!s.empty())
        {
            a.push_back(s.top());
            s.pop();
        }
        
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=a[i])
                return 1;
        }
        return 0;
    }
};
