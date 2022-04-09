class Solution {
public:
    
    int countNegatives(vector<vector<int>>& grid){
        int row = 0;
        int col = grid[0].size()-1;
        int count = 0;
        while(row<grid.size()){
            while(col>=0 && grid[row][col]<0){
                col--;
            }
            if(col==grid[0].size()-1) {
                count+=0; 
            }
            if(col==-1) {
                count+=grid[0].size(); 
            }
            else{
              count+= grid[0].size() - col - 1; 
            } 
            row++;
        }
        return count;
    }
    
    // Better solution : ------>
//     int getNegativeIndex(vector<int> & row, int low , int high){
//         int ans = high+1;
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             if(row[mid]<0){
//                 ans = mid;
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
    
//     int countNegatives(vector<vector<int>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();
//         int count = 0;
//         for(int i=0;i<n;i++){
//             int negativeIndex = getNegativeIndex(grid[i],0,m-1);
//             count += m - negativeIndex;
//         }
//         return count;
//     } 
    
    //Naive solution:::---->>>
    // int countNegatives(vector<vector<int>>& grid) {
    //     int count = 0;
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]<0) count++;
    //         }
    //     }
    //     return count;
    // }
};