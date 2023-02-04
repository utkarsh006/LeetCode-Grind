/* Problem :
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.
*/


/* Approach 1:(HashMap and Multiset)

The lowest group of numbers must be selected such that if all instances of them are removed, the array's size will be cut in half.
It should be evident that the number with the highest frequency should be eliminated first in order to reduce the size of the set of numbers.

We may accomplish this by utilizing a hash map to determine the frequency of each number, sorting the frequencies using a multiset in descending order,
and continuing to add numbers to our set until at least n/ 2 of them have been eliminated.
*/


class Solution
{
    public:
        int minSetSize(vector<int>& arr)
        {
            unordered_map<int, int>mp;
            multiset<int, greater<int>> s;
            for(auto num : arr)
                mp[num]++;
            for(auto [num, freq] : mp)
                s.insert(freq);
            for(int deleted{}, ans{}; auto freq : s)
            {
                deleted += freq, ans++;
                if(deleted >= size(arr) / 2) return ans;
            }
            return -1;
        }
};

/*
Time Complexity : O(N logN)
Space Complexity : O(N)
*/



/* Approach 2:(HashMap and Priority queue)

1. Keep a map with each number's appearances.
2. Now, put the pair (number of occurrences, value of number) into the max-heap.
3. The max-heap will organize these pairings so that the element with the most occurrences is at the top of the max-heap.
4. Since we want the deleted pair to be as small as possible, we must eliminate the element with the highest frequency.
5. Using counter k, we monitor the size of the updated array.
6. Continue popping out the element until either pq is empty or the size is equal to or more than n/2.
7. And m = number of times a pair was taken out of the max-heap.
8. Returning m
*/


#define pr pair<int, int>
class Solution
{
    public:
        int minSetSize(vector<int> &arr)
        {
            priority_queue<pr> pq;
            unordered_map<int, int> mp;
            for (auto x : arr)
                mp[x]++;
            for (auto &x : mp)
                pq.push({x.second, x.first});
            int m = 0;
            int n, k;
            k = n = arr.size();
            while (!pq.empty() && k > n / 2)
            {
                k -= pq.top().first;
                pq.pop();
                m++;
            }
            return m;
        }
};


/*
Time Complexity : O(N logN)
Space Complexity : O(N)
*/
