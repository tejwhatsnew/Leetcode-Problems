class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m);
        vector<int> col(n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        } 

        for(int r = 0; r < row.size(); r++)
        {
            for(int c = 0; c < col.size(); c++)
            {
                if(row[r]==1 or col[c]==1)
                {
                    if(matrix[r][c]!=0)
                        matrix[r][c]=0;
                }
                    
            }    
        }
    }
};