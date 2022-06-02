class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>>newMatrix(m,vector<int>(n,0));
        int row = 0 , col = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newMatrix[row][col]=matrix[i][j];
                row++;
            }
            row = 0;
            col++;
        }
        return newMatrix;
    }
};