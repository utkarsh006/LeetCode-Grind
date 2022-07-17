class Solution {
public:
       vector<int> topKFrequent(vector<int>& nums, int k) 
       {
              vector <int>v;
              map<int,int> m;
           
              for(int i=0;i<nums.size();i++)
                   m[nums[i]]++;
    
              vector<pair<int,int>> temp;
               for(auto x:m)
               {
                 pair<int,int> p{x.second,x.first};
                 temp.push_back(p);
               }
           
              sort(temp.begin(),temp.end());
           
             for(auto it=temp.rbegin(); it!=temp.rend(); it++)
             {
                      if(k-- ==0) break;
                      v.push_back(it->second);
             }
    
                return v;
      }
};
