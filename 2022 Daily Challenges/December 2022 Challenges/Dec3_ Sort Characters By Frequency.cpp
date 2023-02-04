class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int> mp;

        //create the mapping
        for(int i=0; i<s.size(); i++)
           mp[s[i]]++;

        string ans="";
        priority_queue< pair<int,char> >pq;

           for(auto i:mp)
              pq.push({i.second,i.first});

            while(!pq.empty())
            {
                int n=pq.top().first;

                   while(n--)
                   {
                      ans += pq.top().second;
                   }

                   pq.pop();
            }

            return ans;
    }
};
