// Max. no. of soldiers = 5 = column no. 
// put all the rows beside their soldiers count
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector <vector<int>> soldiers (max(rows,cols)+1);
        // max of rows and cols will be stored in the vector soldiers and plus 1 to store
        vector<int>ans;
        
           for(int i=0;i<rows;i++)
           {
               int totalsoldiers = 0;
               
               for(int j=0; j<cols; j++) //for every row count total no. of soldiers
                   totalsoldiers += mat[i][j];
               
               soldiers[totalsoldiers].push_back(i);       
           }
        
          for(int r=0; r<soldiers.size(); r++) 
          {  //iterate over soldiers and get first k values
              for(int c=0; c<soldiers[r].size(); c++)
              {
                  if(k>0)
                      ans.push_back(soldiers[r][c]);
                      k--;
              }
          }
        return ans;
    }
    
};
