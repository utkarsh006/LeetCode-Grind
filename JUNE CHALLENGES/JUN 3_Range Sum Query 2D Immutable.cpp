class NumMatrix {
    public:
        vector<vector<int>> sum;

        NumMatrix(vector<vector<int>>& matrix)
        {
            int row = matrix.size()
            int col = matrix[0].size();

                for(int i=0; i<row; i++)
                {
                    for(int j=1; j<col; j++)
                        matrix[i][j] += matri[i][j-1];
                }

        // FIND PREFIX SUM
            for(int i=1; i<row; i++)
              {
                    for(int j=0; j<col; j++)
                        matrix[i][j] += matrix[i-1][j]
              }
            sum = matrix;  
        }

        int sumRegion(int r1, int c1, int r2, int c2)
        {
            int total = sum[r2][c2];
            int extraSum = ( c1!=0 ? sum[r2][c1-1] : 0) +
                           ( r1!=0 ? sum[r1-1][c2] : 0) -
                           ( r1!=0 && c1!=0 ? sum[r1-1][c1-1] : 0);
            return total-extraSum;
        }
    };