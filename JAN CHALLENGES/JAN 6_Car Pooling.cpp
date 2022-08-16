/* Problem :
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively.
The locations are given as the number of kilometers due east from the car's initial location.
Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
*/


/* Intuition :
Since there are 1000 stops.
Therefore, we merely need to figure out how many passengers may enter and exit at that location.
Carpooling simply refers to packing the vehicle full with people.
*/


/* Approach :
1. Process each trip individually, adding the passenger count to the starting point and deducting it from the destination.

2. If a location's value is positive after all trips have been processed, it means that we are picking up more passengers.

3. A negative figure shows that there are more vacant seats than there were before.

4. Review all of the stops to check whether we have ever gone above the limit of our car.
*/


class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        // From and to is between 0 and 1000. So we are taking an array of size 1001.
        vector<int> lengthOfTrip = vector<int>(1001);
        for (auto trip : trips){
            lengthOfTrip[trip[1]] += trip[0]; // Increment when passenger is on board
            lengthOfTrip[trip[2]] -= trip[0]; // Decrement when they depart
        }
        // Count total passenger for each stop
        int carLoad = 0;
        // Performing a line sweep from 0 to 1000 and tracking its total
        for (int i = 0; i < 1001 && carLoad <= capacity; i++)
        {
            carLoad += lengthOfTrip[i];
            // Rejecting if the car is overloaded somewhere
            if(carLoad > capacity) return false;
        }

        return true; // Accepting only the safe trips



/*
Time Complexity :- O(n), where n is the number of trips.
Space Complexity :- O(max(n, 1001))
*/
