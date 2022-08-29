/* Problem :
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour,
she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
*/


/* Approach :
To consume all of the bananas in piles[i], Koko needs to reach ceiling (1.0 * piles[i] / k).
In order to consume all of the bananas in all of the heaps,
Koko will need hours = sum(math.ceil(1.0 * pile / k) for pile in piles) given k.

We can find the smallest k using binary search.

    If hours are greater than h, then k is too little and low = k + 1.
    If hours are lesser than h, then k is too large and high is equal to k - 1.
    We can try a smaller k and see if high also equals k - 1 if hours == h.
    Initializing low = 1, high = 1000000000 or low = 1, high = max makes sense (piles).

Keep in mind that since we are using a binary search to get k, there is no need to first sort any arrays or lists.
There is not much room for search.
Each time, after checking the current mid, we are certain of the next exact location to search (greater than mid or lower than mid).
*/


class Solution
{
    public:
        int minEatingSpeed(vector<int>& piles, int H)
        {
            int low = 1, high = 1000000000, k = 0;
            while (low <= high)
            {
                k = (low + high) / 2;
                int h = 0;
                for (int i = 0; i < piles.size(); i ++)
                {
                    h += ceil(1.0 * piles[i] / k);
                }
                if (h > H)
                {
                    low = k + 1;
                }
                else
                {
                    high = k - 1;
                }
            }
            return low;
        }
};


/*
Time  Complexity: O(N)
Space Complexity: O(1)
*/
