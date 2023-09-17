class Solution {
public:
    // Class to carry three values at a time
    class tuple
    {
        public:
        int node; // on which current node we are standing
        int mask; // mask of that node
        int cost; // cost of path explore by this node
        tuple(int node, int mask, int cost)
        {
            this -> node = node;
            this -> mask = mask;
            this -> cost = cost;
        }
    };
    
    
    int shortestPathLength(vector<vector<int>>& graph) {
        // total number of nodes present
        int n = graph.size(); // extracting size of graph
        
        
        queue<tuple> q; // queue of class tuple type
        
         // set to take care which path we have already visited
        set<pair<int, int>> vis;
        
        int all = (1 << n) - 1; // if all nodes visited then
            
        // we don't know which node will give us shortest path so intially for all nodes we will store in our queue
        for(int i = 0; i < n; i++)
        {
            int maskValue = (1 << i); // 2 ^ i
            
            tuple thisNode(i, maskValue, 1); // make a tuple for every nod
            
            q.push(thisNode); // push tuple into our queue
            
            vis.insert({i, maskValue}); // also update into our set
        }
        
        // Implementing BFS
        while(q.empty() == false) // until queue is not empty
        {
            tuple curr = q.front(); // extracting front tuple
            q.pop(); // pop from queuu
            
            // if mask value becomes all, that means we have visited all of our nodes, so from here return cost - 1
            if(curr.mask == all) 
            {
                return curr.cost - 1;
            }
            
            // if not, start exploring in its adjcant
            for(auto &adj: graph[curr.node])
            {
                int bothVisitedMask = curr.mask; // current mask
                
                // we are moving from one node o anthor node
                bothVisitedMask = bothVisitedMask | (1 << adj); 
                
                // make tuple of this path
                tuple ThisNode(adj, bothVisitedMask, curr.cost + 1);
                
                // if this path is not explored i.e
                // if it is not present in our set then,
                if(vis.find({adj, bothVisitedMask}) == vis.end())
                {
                    vis.insert({adj, bothVisitedMask}); // insert into set
                    
                    q.push(ThisNode); // also insert into queue
                }
            }
            
        }
        
        // return -1, but this condition will never come
        return -1;
    }
};