Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i = 0;
        int j = numbers.size()-1;
           
            while(i<j) 
            { 
                if(numbers[i]+numbers[j]==target)
                   return {i+1,j+1};
             
               else if(target<numbers[i]+numbers[j])
                         j--;
                 else
                   i++;
            }
        
        return {i+1,j+1};
    }
