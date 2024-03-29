/* You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps. */

// Approach 1 : Recursive

class Solution
	{
    
    vector<int> p;

    int Find(int n)
    {
        if (p[n] == -1) return n;
        p[n] = Find(p[n]);
        return p[n];
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
	    if (a != b)
            p[b] = a;
    }

public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
	{
		int n = s.size();
		p = vector<int>(n, -1);
		for (int i = 0; i<pairs.size(); i++)
		{
			Union(pairs[i][0], pairs[i][1]);
		}

		// set map
		map<int, priority_queue<char, vector<char>, greater<char>>> m;
		for (int i = 0; i<n; i++)
		{
			m[Find(i)].push(s[i]);
		}

		// set ans
		string ans = "";
		for (int i = 0; i<n; i++)
		{
			char now = m[Find(i)].top();
			m[Find(i)].pop();
			ans.push_back(now);
		}

		return ans;
	}

};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)

// Approach 2 : DFS Greedy Approach

/* You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps. */

/*Suppose we have given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
We can swap the characters at any pair of indices in the given pairs any number of times as we want. */

class Solution
	{
	public:
    	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
	{

        vector<unordered_set<int>> g(s.size());
        for(const vector<int>& p: pairs)
            g[p[0]].insert(p[1]), g[p[1]].insert(p[0]);

        vector<int> dfs(s.size(), -1);
        int dfsid = 0;
        for(int i = 0; i < s.size(); i ++)
            if(dfs[i] == -1) dfs(g, i, dfsid ++, dfs);

        vector<vector<int>> poses(dfsid);
        vector<string> order(dfsid, "");
        for(int i = 0; i < dfs.size(); i ++)
            poses[dfs[i]].push_back(i), order[dfs[i]] += s[i];

        for(string& s: order) sort(s.begin(), s.end());

        for(int id = 0; id < dfsid; id ++)
	{

            int index = 0;
            for(int pos: poses[id]) s[pos] = order[id][index ++];
        }
        return s;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int v, int dfsid,
             vector<int>& dfs){

        dfs[v] = dfsid;
        for(int w: g[v])
            if(dfs[w] == -1) dfs(g, w, dfsid, dfs);
    }
};

// Time Complexity: O(|s| + |pairs| + |s|log|s|)
// Space Complexity: O(|s| + |pairs|)
