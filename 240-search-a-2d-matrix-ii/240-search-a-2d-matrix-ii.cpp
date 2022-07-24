class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int col = m-1,row = 0;
        while(col>=0 && row<n){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row+=1;
            else col-=1;
        }
        return false;
    }
};