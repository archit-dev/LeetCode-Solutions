class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        
        for(int row=0;row<m;row++){
            if(matrix[row][0]==0) rowZero = true;
        }
        
        for(int col=0;col<n;col++){
            if(matrix[0][col]==0) colZero = true;
        }
        
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(matrix[row][col]==0){
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                if(matrix[0][col]==0 || matrix[row][0] ==0){
                    matrix[row][col]=0;
                }
            }
        }
        if(rowZero){
            for(int row=0;row<m;row++) matrix[row][0] = 0;
        }
        if(colZero){
            for(int col=0;col<n;col++) matrix[0][col] = 0;
        }
    }
};