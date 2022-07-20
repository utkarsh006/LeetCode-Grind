/*  -> Loop i on all numbers,
    -> Loop j on all numbers,
    -> Check if k = target - i - j is valid.
    
  We have to keep in mind the 3 cases to cover all the possibility of the combination.

      Case 1 : i == j == k
      Case 2 : i == j != k
      Case 3 : i < k && j < k   */

class Solution {
public:
   int threeSumMulti(vector<int>& A, int target) 
   {
        unordered_map<int, long> c;
        for (int a : A) c[a]++;
        long res = 0;
        for (auto it : c)
            for (auto it2 : c) 
            {
                int i = it.first, j = it2.first, k = target - i - j;
                
                if (!c.count(k)) continue;
                
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
};
