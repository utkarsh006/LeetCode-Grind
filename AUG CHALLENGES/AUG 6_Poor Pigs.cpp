/* Problem :
There are buckets buckets of liquid, where exactly one of the buckets is poisonous.
To figure out which one is poisonous, you feed some number of (poor) pigs the liquid to see whether they will die or not.
Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

Choose some live pigs to feed.
For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.
Wait for minutesToDie minutes. You may not feed any other pigs during this time.
After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
Repeat this process until you run out of time.
Given buckets, minutesToDie, and minutesToTest, return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.
*/

/*
Example 1:

Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2
explanation: log(15/15 +1) = log 2 =1
             (log 4)/1 = 2 (output)


Example 2:

Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
explanation: log(30/15 +1) = log 3 = 1.585
             ceil[(log 4)/ 1.585 ] = 2 (output)

*/

/* Approach :
1. The basis for this query is combinatorics.
2. Assume for the moment that we have p pigs that can provide us with an accurate result.
3. Now, the number of tests is equal to (minutesToTest/minutesToDie), or T tests.
4. This indicates that for every T-test, there might be T+1 outcomes, meaning that it could not die in the last instance
    but might do so in the first, second, or even third! Total T+1 Outcomes are therefore feasible.
5. Now we must choose T+1 outcomes for each pig, i.e. (T+1)*(T+1)........*(T+1).
6. The total combination for all p pigs will be (T+1) to the power p, or (T+1)^p, as there are T+1 test rounds.
7. The sum of these combinations now has to be more than or equal to N.
8. Consequently, (T+1)^p >= N will be the need for the answer.
9. Taking the log on both sides, we may obtain the needed information. (p >= log (N)/log (T+1))
10. And hence the return uses the ceil method.
*/

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};


/*
Time Complexity : O(1),
Space Complexity : O(1)
*/
