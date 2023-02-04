/* a b c a c a d b b a
a : 0,3,5,9
b : 1,7,8
c : 2,4
d : 6 

(char): vector<int>
m[x] is the character and corresponding to that character we have to store positions.

*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        map<char,vector<int>> m;
        int i=0, count=0;
        
        for(auto x:s)
            m[x].push_back(i++);
            
        for(int i=0; i<words.size(); i++)
        {
            string curr = words[i];
            // keep a track of previous value(in order)
            int latest = -1;
            
            for(int j=0; j<curr.size(); j++)
            {
                auto it = upper_bound(m[curr[j]].begin(), m[curr[j]].end(), latest);
                // j gives u the idx
                // curr: string
                // m[curr[j]] gives the vector
                
                if(it == m[curr[j]].end()) break;
                    //if itr has reached end no such string is present
                    latest=*it;
                
                if(j==curr.size()-1) count++;
                
            }
        }
        return count;
    }
};
