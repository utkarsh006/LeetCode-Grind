/* Problem :
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
*/


/* Approach :
1. Calculate the cost of moving everyone to City A.

2. Calculate the difference if a Person is transferred to City B.

3. If the last two people are sent to City B instead of City A, 
   you can save the most money because those are the people who cost the most to City A.

4. Sort the differences.

5. Now choose N people with the fewest differences and send them to City B.

6. Add the difference to the total.

7. cost of return.
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        vector<int> diff;
        int mincost = 0;
        
        for(int i = 0; i<costs.size(); ++i)
        {
			// cost to send every person to city A
            mincost += costs[i][0];
			// computing difference if person sent to city B
            diff.push_back(costs[i][1] - costs[i][0]);
        }
		
		// sort the diff vector
        sort(diff.begin(),diff.end());
        
		// picking n persons having least diff
		// sending them to city B
        for(int i=0; i<costs.size()/2; ++i)
        {
            mincost += diff[i];
        }
        
        return  mincost;
        
    }

};

/*
Time complexcity : O(NlogN)
Space Complexcity : O (N)
*/
