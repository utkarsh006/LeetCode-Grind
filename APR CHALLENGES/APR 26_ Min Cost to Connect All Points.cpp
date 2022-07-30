class Solution {
public:
    deque<pair<int,pair<int,int>>>v;
    int par[2001],n,cnt=0;
    // DSU
    int find_par(int r)
    {
         if(par[r]==r)
            return r;
        return par[r]=find_par(par[r]);
    }
    int mst()
    {
        int cost=0; 
          // sort the vector , it will first sort according to cost then indexes
        sort(v.begin(),v.end());
        while(1)
        {
             // a & b are the indexes of current smallest edge
            int a=v[0].second.first;
            int b=v[0].second.second;
            if(find_par(a)!=find_par(b)) // same or not same representer
            {
                par[par[b]]=find_par(a); // make their representer same 
                cost+=v[0].first;
                cnt++;
            }
            if(cnt==n-1) // formed n-1 edges
                break;
            v.pop_front(); // remove the smallest to access the next smallest one 
        }
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n=points.size();
        if(n==1)  // edge case 
            return 0;
         // find distances from each pair of points
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                    int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    v.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        // make each point their own representer
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        return mst();
    }
};