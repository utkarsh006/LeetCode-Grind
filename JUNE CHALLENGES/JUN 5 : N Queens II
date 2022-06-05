/* Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Input: n = 4
Output: 2
Explanation: { {3,1,4,2},{2,4,1,3} } */


class Solution {
public:
     bool issafe(int row, int col, vector<string>& board, int n)
     {
        int duprow = row, dupcol = col;
         
        // upper diagonal
         while(row>=0 && col>=0)
         {
             if(board[row][col]=='Q')
                 return false;
             row--; 
             col--;
         }
         
         //check left row
         col=dupcol; row=duprow;
         while(col>=0)
         {
             if(board[row][col]=='Q')
                 return false;
             col--;
         }
         
          //check lower diagonal
         col=dupcol; row=duprow;
         while(row<n && col>=0)
         {
             if(board[row][col]=='Q')
                 return false;
             row++;
             col--;
         }
         return true;
     }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n)
    { 
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
           for(int row=0; row<n; row++)
           {
               if(issafe(row,col,board,n)) // agar pehle col mai queen place krdi to ye                    
               function check krega ki agle col mein kaha rakh skte ho queen
               {
                   board[row][col]='Q';
                   solve(col+1,board,ans,n);
                   board[row][col]='.';     //backtrack
               }
           }
      
    }
    
    int totalNQueens(int n) 
    {
        vector<vector<string>> ans; 
       vector<string> board(n);
       string s(n,'.');
        
        // storing . in null strings in vector of strings
        for(int i=0;i<n;i++)
            board[i]=s;
        
        solve(0,board,ans,n);       
        return ans.size();
    }
};
