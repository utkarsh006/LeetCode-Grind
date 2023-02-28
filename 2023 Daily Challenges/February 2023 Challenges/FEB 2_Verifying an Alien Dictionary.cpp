class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            int i1 = 0;
            int i2 = 0;
            while (word1[i1] == word2[i2])
            {
                i1++;
                i2++;
            }

            int r = order.find(word1[i1]);
            int l = order.find(word2[i2]);

            if (r > l)
            {
                return false;
            }
        }
        return true;
    }
};