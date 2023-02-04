/* Problem :
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/


/* Approach 1: Using Min-Heap
1. Using a min-heap of size k is the plan here.
2. A minimum heap of size k will now keep k elements with the lowest k elements at the top.
3. We simply go through our nums array after saving the first k elements of nums in the min-heap, and if the element at the top of the min-heap is smaller than the element in nums, we extract the top element of the min heap and push the current element.
4. In this way, the kth largest element at the top of the min-heap are kept track of.
*/
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
		//Min-Heap Initialization
        priority_queue<int, vector<int>, greater<int>> pq;
		//Push first k elements into min-heap
        for(int i=0;i<k;i++) pq.push(nums[i]);
		//If the element at top of min-heap is smaller, remove it and add new element
        for(int i=k;i<nums.size();i++)
            {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
		//Return the top (smallest) of min-heap
        return pq.top();
    }
};
/* Time and Space Complexities :
Time Complexity = (O(N) + O(kLogN)) => O(N LogN)
Space Complexity = O(N)
*/


/* Approach 2: Using Sorting
 The Idea here is to simply sort the array in non-increasing/decreasing order and return the element at kth-1 index...
*/
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int len = nums.size();
        // sort the array
        sort(nums.begin(), nums.end());
        // return kth largest
        return nums[len-k];
    }
};
/* Time and Space Complexities :
Time Complexity = O(N LogN)
Space Complexity = O(1)
*/
