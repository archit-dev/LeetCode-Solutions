class Solution {
public:
    int getNegativeIndex(vector<int> & row, int low , int high){
        int ans = high+1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(row[mid]<0){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    int countNegatives(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            int negativeIndex = getNegativeIndex(grid[i],0,m-1);
            count += m - negativeIndex;
        }
        return count;
    } 
    
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