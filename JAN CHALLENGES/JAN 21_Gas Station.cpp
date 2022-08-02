/* Problem:
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station.
You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index
if you can travel around the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
*/

/* Note:
Completing the circuit entails beginning from i and returning to i.
Both input arrays are non-empty and of equal size.
The elements of the input arrays are all non-negative integers.

As we all know, a unique solution exists, if exists.
When we look at the issue, we should be concerned that the overall amount of gas should be more than the whole cost.
The sole consideration is determining the beginning location.
*/

/* Approach:
Assuming our start=0, we traverse the array from index 0 to the last index, doing total += gas[i] - cost[i] and current += gas[i] - cost[i] at each position.
If current = 0, it's obvious that you can't start from that index since you don't have enough gas to proceed till the next index, therefore we increment our start to the next index (start=i+1).
After traversing the arrays, if the total < 0, it signifies that no matter where we start, we can't return to that station, thus we return -1.
In contrast, if the total is more than 0, we can begin at the station start and return to that index. We return start.
*/

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int current = 0, total = 0, diff = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            diff = gas[i] - cost[i];
            total += diff;
            current += diff;
            if(current < 0)
            {
                start = i + 1;
                current = 0;
            }
        }
        if(total >= 0)
        {
            return start;
        }
        return -1;
    }
};

/*
Time Complexity : O(N),
Space Complexity : O(1).
*/
