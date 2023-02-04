/*
Problem: Maximize Distance to Closest Person

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat,
 and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

Example:

        Example 1:

            Input: seats = [1,0,0,0,1,0,1]
            Output: 2
            Explanation: 
            If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
            If Alex sits in any other open seat, the closest person has distance 1.
            Thus, the maximum distance to the closest person is 2.

        Example 2:

            Input: seats = [1,0,0,0]
            Output: 3
            Explanation: 
            If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
            This is the maximum distance possible, so the answer is 3.

        Example 3:

            Input: seats = [0,1]
            Output: 1
 
*/

/*
Approach-1 (Brute Force)

1. We will make 2 vectors left and right of n size and we will initialize their values by n so that it 
doesn't make any erros while taking maximum, left vector will be for storing distances from left to right and 
right vector will be for storing distances from right to left.

2. We will keep track of max distances from both left and right side.

3. So firstly we will traverse for left vector from left to right, if seats[i]==1 then it means seat is 
already occupied so we will update left [i] as 0 in the vector , else if i is greater than 0 then we will update 
left[i] as left[i-1](prev value) +1 .

4. Similarly we will traverse for right vector from right to left , so if seats[i]==1 that means seat is occupied 
so it will be 0 otherwise if i is not last position then right[i] will have the value as right[i+1]+1.

5. If i==0 and seats[i]==0 then it means there is no left[i-1] so we will not update this value of left[i] and
 it will have it's value as n and same for if i==n-1 and right[i]==0 so it will also have n as value.

6. In the end for every iteration find min of left[i],righ[i] and take it's max with ans. So that's how
 we will get maximum distance with closest person. 
*/

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        vector<int> left(n, n);
        vector<int> right(n, n);

        for (int i = 0; i < n; i++)
        {
            // it means it's already occupied
            if (seats[i] == 1)
            {
                // so we will keep the distance as 0 here
                left[i] = 0;
            }
            else if (i > 0)
            {
                // if i is any value greater than 0 then in left[i] we will add 1 along with the prev value
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (seats[i] == 1)
            {
                right[i] = 0;
            }
            else if (i < n - 1)
            {
                //if i is any value less than n-1 then in right[i] we will add 1 along with the next value right[i+1]
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 0)
            {
                ans = max(ans, min(left[i], right[i]));
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(N)
*/


/*
Approach-2 (Optimized)

1. Since in this ques we can have 3 condition
    - beginning zeros :  to keep their track we will use prefix variable
    - middle zeros: to keep their track we will use curr variable
    - ending zeros: to keep their track we will use suffix variable

2. Initialize all these variable with -1 and initialize a variable zeros=0 to keep a track of all the zeros.

3. Now  if seats[i]==1 then check first if prefix ==-1 if yes, then store zeros if prefix ,it means that if 
there are any zero at the beginning then zeros will get updated and if not then zeros will be 0 but in both cases 
when we find seats[i]=1 then we will update our prefix for the first time.

4. If prefix is not -1 that means we have already updated prefix(even if it doesn't have any beginning zeros). 
So we will update curr this time for middle zeros and it will be max of curr,zeros that means all the middle zeros 
we have ever got from them we will take max as curr.

5. and after that we will update zeros as 0 so that it start it's count of zero all over again, if seats[i]!=1 
then keep incrementing zeros.

6. Atlast assign zeros to suffix , if there were zero in the end of array then zeros will assign it to suffix 
otherwise suffix will have 0.

7. Atlast find the max of suffix,prefix and curr and return the ans.
*/


class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int prefix = -1, curr = -1, suffix = -1, zeros = 0;

        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                if (prefix == -1)
                {
                    prefix = zeros;
                }
                else
                {
                    curr = max(zeros, curr);
                }
                zeros = 0;
            }
            else
            {
                zeros++;
            }
        }

        suffix = zeros;

        return max(max(prefix, suffix), (curr + 1) / 2);
    }
};

/*
Time Complexity: O(N)
Space Complexity:O(1)
*/