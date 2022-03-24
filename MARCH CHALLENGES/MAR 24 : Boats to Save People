/*Sort people.
For the current heaviest person, we try to let him go with the lightest person.
As all people need to get on the boat.
If the sum of weight is over the limit, we have to let the heaviest go alone.
No one can take the same boat with him.

At the end of for loop, it may happend that i = j.
But it won't change the result so don't worry about it. */


    class Solution{
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(),people.end());
        int i = 0, j = people.size() - 1,cnt = 0;
        
        while(i <= j)
        {   
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(people[i] + people[j] <= limit)
            {
                ++i;
                --j;
            }
            // if sum is over the limit,
            // heaviest will go alone.
            else
                --j;
            
            ++cnt;  // number of boats
        }
        
        return cnt;
        
    }
};
