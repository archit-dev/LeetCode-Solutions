class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRowZero = false;
        bool isColZero = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    if(matrix[i][j]==0){
                        isRowZero = isColZero = true;
                    }
                }
                else if(i==0){
                    //to find if there is original 0 in row0
                    if(matrix[i][j]==0) isRowZero = true;
                }
                else if(j==0){
                    //to find if there is original 0 in col0
                    if(matrix[i][j]==0) isColZero = true;
                }
                else{
                    if(matrix[i][j]==0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        
        for(int i=row-1;i>=1;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isRowZero){
            for(int i=0;i<col;i++){
                matrix[0][i] = 0;
            }
        }
        if(isColZero){
            for(int i=0;i<row;i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};