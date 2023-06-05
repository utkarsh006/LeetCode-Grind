class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int point = coordinates.size();

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2 ; i< point; i++)
        {
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // y - y1 / x - x1 != y - y2 / x - x2
            // Division may cause division by zero error.

            if((y - y1) * (x - x2) != (y - y2) * (x - x1))
            {
                return false;
            }
        }
        return true;
    }
};

/*
Explaination: In contraints we are given we can minimum of 2 points and maximum of 1000 points.
And last contraint is important that coordinate contains no duplicate point .

If we are given two points lets assume A and B. So, the slope between these two points will be tan thetha ie, equal to perpendicular/base = y2-y1/x2-x1. 
So, if we have many points in a straight line then they will be having the same slope value. So, in question we can have greater than equal to 2 points.
So, lets assume we have three points. In this case we just need to find the slope between two points and using this slope we can iterate for other points 
and that's how we will start iterating from 3rd point and then we will keep calculating the slope using the previous point. If this present slope is not equal
to pre calculated slope then it is not a straiht line.

In order to avoid the problem of same points we can just reformulate the formula from
y2-y1/x2-x1 = y3-y2/x3-x2 to (y2-y1)x(x3-x2)= (x2-x1)(y3-y2). Bcz Division may cause division by zero error.

T.C = O(N)
s.c = O(1)
*/
