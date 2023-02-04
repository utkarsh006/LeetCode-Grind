// Word Ladder

/* Problem :
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

/* Approach :
1. First, we determine whether our endword is included in the word list or not.
Otherwise, we return 0.
2. The first thing we need to do is figure out how to create a graph for the provided question.
Our begin word will be the first node in the graph, and our end word will be the last node.
3.We change a maximum of one character from each node's string for its neighbor and determine whether or not it appears in our wordList.
The modified word then becomes the specified node's neighbor.
*/

class Solution
{
public:
    int ladderLength(string &beginWord, string &endWord, vector<string> &wordList)
    {
    	unordered_set<string> s(wordList.begin(), wordList.end());

    	if(s.find(endWord) == s.end()) return 0;
    	int cnt = 0;
    	queue<string> q;
    	// pushing the starting node into queue
    	q.push(beginWord);
    	while(!q.empty())
            {
    		auto size = q.size();
    		cnt++;
    		while(size--)
    		{
    			auto currWord = q.front(); q.pop();
    			// finding the next word which can be formed after currWord
    			for(int i = 0; i < currWord.size(); ++i)
    			{
    				string tmp = currWord;
    				for(char ch = 'a'; ch <= 'z'; ++ch)
    				{
    					tmp[i] = ch;
    					// if new word is same as curr word, ignore
    					if(tmp.compare(currWord) == 0) continue;
    					if(tmp.compare(endWord) == 0) return cnt + 1;
                        if(s.find(tmp) != s.end())
                        {
                        	q.push(tmp);
                        	s.erase(tmp);
                        }
    				}
    			}
    		}
    	}
    	return 0;
    }
};


/* Complexities:
Time Complexity : O(N * L * 26),
Space Complexity : O(N),
where L : length of words, where N : size of wordList
*/
