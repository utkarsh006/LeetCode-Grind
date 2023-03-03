class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {

        int n = ideas.size();

        unordered_map<string, int> m;
        for (string idea : ideas)
        {
            m[idea]++;
        }

        vector<vector<int>> starts_accepts(26, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            string str = ideas[i];
            int starts = ideas[i][0] - 'a';

            for (char c = 'a'; c <= 'z'; c++)
            {
                str[0] = c;
                if (m.find(str) == m.end())
                {
                    int accepts = str[0] - 'a';
                    starts_accepts[starts][accepts]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            string str = ideas[i];
            int starts = ideas[i][0] - 'a';

            for (char c = 'a'; c <= 'z'; c++)
            {
                str[0] = c;
                if (m.find(str) == m.end())
                {
                    int accepts = str[0] - 'a';
                    ans = ans + starts_accepts[accepts][starts];
                }
            }
        }

        return ans;
    }
};