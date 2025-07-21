class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroInFirstRow = 0, zeroInFirstCol = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0)
                    {
                        zeroInFirstRow = 1;
                    }
                    if(j==0)
                    {
                        zeroInFirstCol = 1;
                    }
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(zeroInFirstCol)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }
        if(zeroInFirstRow)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};

