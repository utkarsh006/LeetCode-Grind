## Problem Statement

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 
## Examples

#### Example 1:

Input: n = 2, trust = [[1,2]]

Output: 2

#### Example 2:

Input: n = 3, trust = [[1,3],[2,3]]

Output: 3

#### Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]

Output: -1
 

## Constraints:

```

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n

```


## Approach

It is given that :- 

                1) The Town Judge trusts no one, this implies that the number of outgoing edges of the town Judge must be 0

                2) Also,Everyone trusts the Town judge,this implies that the number of incoming edges of the town Judge must be n-1.

where,n=no. of vertices

- Therefore, we have to return that vertex as answer which has an outdegree of 0 and indegree as n-1. 

Intuition :- Storing the no. of outgoing & incoming edges for each nodes .If a node has 0 outgoing edges & n-1 (n=no. of nodes) incoming edges,
then it's the Judge else return -1.

## Code

```cpp

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {

        unordered_map<int,int>out;
        unordered_map<int,int>in;
        
        for(auto index : trust)
        {
            out[index[0]] ++; //finding outgoing edges for each vertex
            in[index[1]]++;//finding incoming edges for each vertex
        }
        
        for(int i =1;i<=n;i++)
        {
            if(out[i] == 0 && in[i] == n-1)
                return i;
        }
        return -1;
    }
};

```

#### TC=O(n) + O(n) , for storing the incoming & outgoing edges + for iterating over unordered maps to find the town judge

#### SC=O(n) + O(n) , for storing the incoming & outgoing edges
