class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x<n && x>=0 && y<m && y>=0) return true;
        return false;
    }
    
    void dfsHelper(vector<vector<char>>&grid,vector<vector<int>>&vis
                  ,int row,int col)
    {
        vis[row][col] = 1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int newX = row+dx[i];
            int newY = col+dy[i];
            if(isValid(newX,newY,grid.size(),grid[0].size()))
            {
                if(grid[newX][newY]=='1' && vis[newX][newY]==-1){
                    dfsHelper(grid,vis,newX,newY);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int numIslands = 0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && vis[row][col]==-1){
                    dfsHelper(grid,vis,row,col);
                    numIslands+=1;
                }
            }
        }
        return numIslands;
    }
};