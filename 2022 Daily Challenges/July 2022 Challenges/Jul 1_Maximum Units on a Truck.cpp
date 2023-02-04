Example 1:
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Code:

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	sort(begin(boxTypes), end(boxTypes), [](auto& a, auto& b){ return a[1] > b[1];}); // sort by number of units / box
	int maxUnits = 0;
	for(auto& box : boxTypes) {
		if(truckSize <= 0) break;                    // keep choosing greedily till you run out of truckSize 
		maxUnits += min(truckSize, box[0]) * box[1]; // add (no of box * units) in that box
		truckSize -= box[0];
	}
	return maxUnits;
}
};
