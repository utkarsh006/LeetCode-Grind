/* Problem :
A car travels from a starting position to a destination which is target miles east of the starting position.
There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives.
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
*/


/* Approach : (Max Heap)
1) All of the stations that a car can get to with its current gasoline supply must be taken into consideration.
2) From all the stations, we must pull over at the one that can give the car the most fuel.

Cases to Think About ---

1. What if there is not enough petrol in the vehicle to get to a station?
2. What if the vehicle stops at every station but still runs out of fuel before reaching the destination?
    -- As the car cannot reach the target in either of the aforementioned scenarios, we must return -1.

The key right now is to decide which Data Structure to apply in this circumstance.

As we have seen, it's crucial to keep track of all the stations a car can reach so that it can stop at the one with the most fuel.
It is obvious that we must monitor the maximum amount of fuel in all of the stations that are within reach.
And Max Heap might be employed to actually achieve that.
*/


class Solution
{
    public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
        {
            int currentDistance = startFuel;
            int idx = 0;
            priority_queue<int> maxHeap;
            int minStops = 0;

            while(currentDistance < target)
            {
                while(idx < stations.size() and stations[idx][0] <= currentDistance)
                    maxHeap.push(stations[idx++][1]);

                if(maxHeap.empty())
                    return -1;

                currentDistance += maxHeap.top();
                maxHeap.pop();
                minStops += 1;
            }
            return minStops;
        }
};


/*
Time Complexity : O(N logN)
Space Complexity : O(N)
 N --> Number of Fuel Stations.
*/
