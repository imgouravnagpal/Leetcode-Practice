class Solution {
public:
    void transpose(vector<vector<int>>& matrix)
    {
        int i = 0,j=0,n=matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return;
    }
    void reverseArray(vector<int>& arr)
    {
        int i = 0;
        int j = arr.size()-1;
        while(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            reverseArray(matrix[i]);
        }
        return;
    }
};