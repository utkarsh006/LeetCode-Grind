/* Problem :
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary).
You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary.
Since the answer can be very large, return it modulo 109 + 7.
*/


/* Approach 1: (Brute Force)
Let's start with the brute-force method of answering the question.
We need to find as many paths as possible to get the ball out of the grid's bounds while using no more than maxMoves moves.
So we'll simply test every conceivable move from the current cell and return 1 if we go out of boundaries.
If all of our maxMoves have been exhausted, return 1 if we are currently out, otherwise return 0.
This operation will be repeated for each cell, and the values produced for each conceivable move from a cell will be summed.
*/

bool outOfBounds(int m, int n, int r, int c)
{
    // condition for out of the grid
	return r < 0 || r >= m || c < 0 || c >= n;
}
int findPaths(int m, int n, int maxMove, int r, int c)
{
	bool isOut = outOfBounds(m, n, r, c);
	// check if out of the grid or out of moves
	if(isOut || !maxMove) return isOut;
	// try all moves from the current cell
	// add up all paths taking the ball out of bounds
	return (findPaths(m, n, maxMove-1, r + 1, c)  +
			findPaths(m, n, maxMove-1, r - 1, c)  +
			findPaths(m, n, maxMove-1, r, c + 1)  +
			findPaths(m, n, maxMove-1, r, c - 1)) % (1e9 + 7);
}
/*
Time Complexity : O(4^ maxMove)
Space Complexity : O(maxMove)
*/


/* Approach 2: (Memoization)
We can see that we are doing a lot of calculations over and over again. 
We can avoid re-calculations by storing and re-using computed solutions rather than re-computing them. When we have maxMove remaining, 
there will always be the same number of ways to reach out of bounds from cell (i,j).

As a result, we can use dynamic programming to save the previously specified state. 
We utilize a dp matrix, where dp[i][j][maxMove] denotes the number of ways to take the ball out of bounds from cell (i,j), 
with maxMove being the maximum number of moves. 
Every time we calculate the result for a certain cell with a certain amount of moves remaining, 
we save this state in our matrix and return it immediately whenever it is needed in the future.
*/

const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}};  // initializing all elements to -1
public:    
	bool outOfBounds(int m, int n, int r, int c) 
	{
		return r < 0 || r >= m || c < 0 || c >= n;
	}
	int findPaths(int m, int n, int maxMove, int r, int c) 
	{        
		bool isOut = outOfBounds(m, n, r, c);
		if(isOut || !maxMove) return isOut;
		if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  // return if already computed result
		dp[r][c][maxMove] = 0;   // elements are initalized to -1, so set to 0 before exploring moves
		for(int i = 0; i < 4; i++)
		{
			dp[r][c][maxMove] = (dp[r][c][maxMove] + findPaths(m, n, maxMove-1, r + moves[i][0], c + moves[i][1])) % mod;
		}
		return dp[r][c][maxMove];
	}


/*
Time Complexity : O(m * n * maxMove)
Space Complexity : O(1)
*/


/* Approach 3: (Dynamic Programming)
We can also use dp tabulation to solve it iteratively.
Again, we utilize the dp matrix, with dp[i][j][M] denoting the number of ways to reach the cell (i,j) from outside the grid in at most M movements.
We will iterate over each cell of the grid for moves M=1...maxMove, updating the total number of ways to reach the current cell as the sum of the number of ways to reach its nearby cells in M-1 moves each time.
If the adjacent cell is not discovered, we are out of bounds and can add another path to the total.
Finally, dp[r][c][MaxMove] will hold the number of ways to reach outside grid in maximum maxMove (r,c).
*/

class Solution 
{
public:
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int findPaths(int m, int n, int maxMove, int r, int c)
	{
		auto outOfBounds = [&](int m, int n, int r, int c)
		{
		    return r < 0 || r >= m || c < 0 || c >= n;
	        };
	        // As the limitations are minimal enough, we may utilize a 51x51x51 dp matrix directly instead of a dynamic one.
		uint dp[51][51][51]{};
		// iterate for all available moves
		for(int M = 1; M <= maxMove; M++)
		{
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
				{
					// for each cell, try all 4 possible moves
					for(int k = 0; k < 4; k++)
					{
						if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M]++;
						else dp[i][j][M] += dp[i + moves[k][0]][j + moves[k][1]][M-1] % mod;
					}
				}
			}
	        }
		return dp[r][c][maxMove] % mod;
	}
};
/*
Time Complexity : O(m * n * maxMove)
Space Complexity : O(1)
*/


/* Approach 4:(Space Optimized DP)
We can see that we always access the value held for the preceding transfer.
As a result, we don't need to store all maxMove in our dp array. 
We only need dp[i][j][M-1] (matrix recording the number of pathways to (i,j) in M-1 movements at most) 
and dp[i][j][M] at any moment (matrix that we update for M moves using the previous matrix).

In many dynamic programming issues, alternating between two rows of dp (in the case of optimization from 2d to 1d) or, 
in this example, alternating between two matrices successfully reduces the dp from a 3D matrix into 2x 2D matrix. 
We can switch between them by using the AND (&) operator and the number 1.

Another minor detail is that we must set dp[i][j][M&1] to 0 before we begin adding pathways from the matrix storing values for M-1 movements, 
because dp[i][j][M&1] is now holding values for M-2 moves.
*/

const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int findPaths(int m, int n, int maxMove, int r, int c)
{
	// The majority of the code remains same
	// just alternate indexing by adding a &1 term when indexing.
	auto outOfBounds = [&](int m, int n, int r, int c)
	{
		return r < 0 || r >= m || c < 0 || c >= n;
	};
	uint dp[50][50][2]{};        
	for(int M = 1; M <= maxMove; M++)
	{
		for(int i = 0; i < m; i++) 
		{
			for(int j = 0, k; j < n; j++)
			{
				for(k = 0, dp[i][j][M & 1] = 0; k < 4; k++)
				{
					if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M & 1]++;
					else dp[i][j][M & 1] += dp[i + moves[k][0]][j + moves[k][1]][(M-1) & 1] % mod;
				}
			}
		}
	}
	return dp[r][c][maxMove & 1] % mod;
}

/*
Time Complexity : O(m * n * maxMove)
Space Complexity : O(1)
*/
