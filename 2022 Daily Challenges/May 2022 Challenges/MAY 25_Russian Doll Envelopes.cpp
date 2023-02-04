// MAY 25 : Russian Doll Envelopes

/* Problem :
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
*/

/* Approach :
1. Sort the envelopes in decreasing height and increasing breadth order.
2. Apply LIS to heights next.
3. LIS:
a) To save the sequence, make a tmp_arr.
b) Append curr_elem to tmp_arr if curr_elem in arr exceeds tmp_arr.back().
c) Replace the elem in tmp_arr if necessary so that curr_elem equals tmp_elem and the increasing nature of tmp_arr is not broken.
d) (Tmp_arr's binary search for curr_elem will yield the correct index.) Bring back the length of tmp_arr.
*/

class Solution
{
public:
    static bool helper(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return (a[1] > b[1]);
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), helper);
        vector<int> tmp;
        tmp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++)
            {
            int curr_elem = envelopes[i][1];
            if (tmp.back() < curr_elem)
            {
                tmp.push_back(curr_elem);
            }
            else
            {
                int idx = lower_bound(tmp.begin(), tmp.end(), curr_elem) - tmp.begin();
                tmp[idx] = curr_elem;
            }
        }
        return tmp.size();
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
