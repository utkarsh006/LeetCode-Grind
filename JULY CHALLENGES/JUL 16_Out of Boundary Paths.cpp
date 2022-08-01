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


/* Approach 2: (Dynamic Programming)
We can also use dp tabulation to solve it iteratively.
Again, we utilize the dp matrix, with dp[i][j][M] denoting the number of ways to reach the cell (i,j) from outside the grid in at most M movements.
We will iterate over each cell of the grid for moves M=1...maxMove, updating the total number of ways to reach the current cell as the sum of the number of ways to reach its nearby cells in M-1 moves each time.
If the adjacent cell is not discovered, we are out of bounds and can add another path to the total.
Finally, dp[r][c][MaxMove] will hold the number of ways to reach outside grid in maximum maxMove (r,c).
*/

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
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
                // for each cell, try all 4 possible moves
				for(int k = 0; k < 4; k++)
					if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M]++;
					else dp[i][j][M] += dp[i + moves[k][0]][j + moves[k][1]][M-1] % mod;
	return dp[r][c][maxMove] % mod;
}
/*
Time Complexity : O(m * n * maxMove)
Space Complexity : O(1)
*/
