class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int startRow = 0;
        int startCol = col-1;
        while(startCol>=0 && startRow<row){
            if(matrix[startRow][startCol]==target) return true;
            else{
                if(matrix[startRow][startCol]>target){
                    startCol--;
                }else{
                    startRow++;
                }
            }
        }
        return false;
    }
};