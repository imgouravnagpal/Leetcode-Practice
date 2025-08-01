class Solution {
public:
    int n;
    void Reverse_Each_Row(vector<vector<int>>& matrix)
    {
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    void Transpose(vector<vector<int>> & matrix)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        Transpose(matrix);
        Reverse_Each_Row(matrix);
    }
};