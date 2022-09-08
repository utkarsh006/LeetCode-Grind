/* Problem :
There is a broken calculator that has the integer startValue on its display initially.
In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target,
return the minimum number of operations needed to display target on the calculator.
*/


/* Approach :
The goal is to make target equal to startvalue and then count the number of actions.
Instead of changing startvalue to target, we shall do the opposite.
We are converting target to startvalue in two phases.

    If the desired value is odd, we'll make it even by adding one.

    If the target is an even number, we shall divide by two.

    and after these two operations, we will count min operations till targetvalue exceeds startvalue.
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        int result=0;
        while(target>startValue)
        {
            result++;
            if(target%2==0)
                target=target/2;
            else
                target+=1;
        }
        result=result+(startValue-target);
        return result;
    }
};


/*
TIME CONPLEXITY :- O(logn)
SPACE COMPLEXITY :- O(1)
*/
