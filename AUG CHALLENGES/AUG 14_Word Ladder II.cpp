/*
Problem Statement:

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
- Every adjacent pair of words differs by a single letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
- sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. 
Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: 
    There are 2 shortest transformation sequences:
        "hit" -> "hot" -> "dot" -> "dog" -> "cog"
        "hit" -> "hot" -> "lot" -> "log" -> "cog"


Approach (BFS, Backtracing):

Moving Forward: start from begin
1. Each level, find all connected nodes to the nodes of the current level in the record and add those to the record for the next level
2. Delete node from wordList to prevent revisiting and forming cycles
3. Repeat the above steps until we reach end or we add no new nodes to the record for next level

Moving Backward: start from end

1. Move backward to compute only the paths that can connect from begin to end
2. Do the same steps as moving forward but this time we will not record nodes but contruct our paths
3. Construct paths in reversing order to have paths from begin to end

*/

class Solution 
{
public:
    bool isConnected(string s,string t)
    {
        int c=0;
        for (int i=0;i<s.length();i++)
            c+=(s[i]!=t[i]);
        return c==1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;        
        vector<vector<string>> nodes;   
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        if (!dict.count(endWord)) return ans;
        dict.erase(beginWord);   
        
        bool reached = false;
        nodes.push_back({beginWord});
        
        while (dict.size() && !reached) 
        {                        
            vector<string> last = nodes.back();
            vector<string> curr;
                        
            for (int i = 0; i < last.size() && !reached; i++) 
            {
                unordered_set<string> visited;
                string from = last[i];                                
                // Check all the nodes that connect to the nodes of the previous level                
                for (auto& to : dict) 
                {                    
                    if (visited.count(to)) continue;
                    if (!isConnected(from, to)) continue;                                        
                    // If one of them is "endWord" then we can stop 
                    // because this level is the shortest distance from begin
                    if (to == endWord) 
                    {                        
                        reached = true; 
                        break;
                    }
                    // Otherwise, add nodes for the current level
                    curr.push_back(to);   
                    visited.insert(to);                    
                }   
                // Delete the visited to prevent forming cycles            
                for (auto& visited : visited) 
                {                
                    dict.erase(visited);
                }
            }
            
            // If endWord found in this level
            if (reached) break;
            
            // If can't add any new nodes to our level
            if (!curr.size()) break;
            
            // Otherwise, record all nodes for the current level
            nodes.push_back(curr);            
        }
        
        // If tried but not found
        if (reached == false) return ans;
        
        // Move backward
        ans.push_back({endWord});          
        for (int level = nodes.size() - 1; level >= 0; level--) 
        {                        
            int alen = ans.size();
            while (alen) 
            {
                vector<string> path = ans.back();
                ans.pop_back();
                string from = path.front();                
                for (string &to : nodes[level]) 
                {                    
                    if (!isConnected(from, to)) continue;
                                        
                    vector<string> newpath = path;
                    newpath.insert(newpath.begin(), to);
                    ans.insert(ans.begin(), newpath);
                }    
                alen--;
            }             
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/