/* Problem :
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/


/* Approach : (DFS)
1. Verify whether root is NULL. return if true.
(Cycle prevention requires a visited hash map. Take the undirected rectangular shape graph A->B->C->D->A as an example. It will continue if we do not keep visiting.)

2. If the answer is no, clone the node and add the entry pair as visited[node] = clonedNode to the hash map.

3. Do DFS for each neighbor iteratively. We may additionally populate the neighbors of a cloned node with the outcome of recursive calls while we are looping over this neighbor list.

4. Upon each recursive call, return clonedNode.
*/

class Solution
{
    private:
        unordered_map<Node*, Node*> visited;
    public:
        Node* cloneGraph(Node* node)
        {
            if(node == NULL)
                return node;
            if(visited[node])
                return visited[node];

            Node* cloned = new Node(node->val);
            visited[node] = cloned;

            for(auto nei: node->neighbors)
            {
                cloned->neighbors.push_back(cloneGraph(nei));
            }
            return cloned;

        }
};



/* Approach : (BFS)
The steps for BFS are nearly same. In level order traversal, the most of the information is comparable.
We thus utilize queue here rather than the stack to handle the nodes and their neighbors.
The current root is variable curr. We repeat the process over its offspring.
If the neighbor is not visited, two things happen inside the neighbor loop:

    1. Clone the neighbor and add the entry <neighbor, clonedNeighbor> to the hash map that has been visited.
    2. shuffle the neighbor up in line. This is done in order to handle the neighborhood kids in subsequent queue iterations.

In a similar manner, we populate the neighbors vector or list.
*/

Node* cloneGraph(Node* node)
{
        if(node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while(!Q.empty())
        {
            int n = Q.size();
            Node* curr = Q.front();
            Q.pop();
            for(auto nei: curr->neighbors)
            {
                if(!visited[nei])
                {
                     visited[nei] = new Node(nei->val);
                     Q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];
}


/*
Time Complexity :- O(N),
Space Complexity :- O(N)
*/
