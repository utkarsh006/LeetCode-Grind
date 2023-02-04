## Problem Statement 
 You are given an array of strings products and a string searchWord. Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products. Return a list of lists of the suggested products after each character of searchWord is typed.

## Constraints:

- 1 <= products.length <= 1000
- 1 <= products[i].length <= 3000
- 1 <= sum(products[i].length) <= 2 * 104
- 1 <= searchWord.length <= 1000
- All the strings of products are unique and consists of lowercase alphabets.

## Algorithm:

1. Sort the products vector lexicographically.
2. Iterate each character of the searchWord adding it to the prefix to search for.
3. After adding the current character to the prefix binary search for the prefix in the input.
4. Add next 3 strings from the current binary search start index till the prefix remains same.
5. Another optimization that can be done is reducing the binary search space to current start index



## Example
### Input: 
```
products = ["bags","baggage","banner","box","cloths"]
searchWord = "bags"
```
### Output: 
```
result = [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
```

## Code
```cpp
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end()); //sort the given vector of strings lexicographically 
        int n=searchWord.size();
        vector<vector<string>>res(n,vector<string>{});

        for(auto& product:products){
            for(int i=0;i<n;i++){
                 if(product[i]!=searchWord[i]) //if not match break out of loop
                    break;

                if(product[i]==searchWord[i] && res[i].size()<3){ //if matches then push into res vector
                    res[i].push_back(product);
                }
            }
        }
        return res;
    }
};
```
## Time and Space Complexities
### Time Complexity = O(N * log N)
### Space Complexity = O(N)
