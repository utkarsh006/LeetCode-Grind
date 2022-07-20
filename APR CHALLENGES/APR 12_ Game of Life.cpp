class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
       int dx[8] = {-1,-1,0,1,1,1,0,-1};
       int dy[8] = {0,1,1,1,0,-1,-1,-1};
       int rows = board.size();
       int col = board[0].size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                int count = 0;
                for(int k=0;k<8;k++)
                {
                    int nextI = i+dx[k];
                    int nextJ = j+dy[k];
                      if(nextI >= 0 && nextI<rows && nextJ >=0 &&
                         nextJ<col && (board[nextI][nextJ] == 1 ||
                                        board[nextI][nextJ] == 2))
                          count++;
                }
                
                if(board[i][j] == 0 && count == 3) board[i][j] = 3;
                else if(board[i][j] == 1)
                {
                    if(count<2 || count>3) board[i][j] = 2;
                }
            }
        }
        
           for(int i=0; i<rows; i++)
           {
               for(int j=0; j<col; j++)
               {
                   if(board[i][j] == 2) board[i][j] = 0;
                   if(board[i][j] == 3) board[i][j] = 1;
               }
           }
    }
};
