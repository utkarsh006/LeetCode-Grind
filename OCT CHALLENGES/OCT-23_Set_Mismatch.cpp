Approach :
1)First take a set {set avoids the duplicates and stores only the unique elements}
2)Find the sum of all elements in the set and store in the actual_sum
3)Now find the sum of all the numbers from 1 to n and store in expected_sum
4)(expected_sum-actual_sum) will give the missing element
5)(sum_of_vector_elements-actual_sum) gives the repeated number 


vector<int> findErrorNums(vector<int>& nums) {
    int sum_of_vector_elements = accumulate(nums.begin(), nums.end(), 0);

    set<int> s;
    for(auto &i: nums){
        s.insert(i);
    }

    int actual_sum = accumulate(s.begin(), s.end(), 0);

    int repeatedNum = sum_of_vector_elements - actual_sum;
	int n = nums.size();
  int expected_sum=n * (n+1)/2;
    int missingNum =  expected_sum- actual_sum;

    return {repeatedNum, missingNum};
}

Time Complexity:O(n)
Space Complexity:O(n)
