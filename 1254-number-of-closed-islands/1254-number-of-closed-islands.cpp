class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    int bfsHelper(int cr,int cc,int n,int m,vector<vector<int>> & grid,
                 vector<vector<bool> > & visited)
    {
        visited[cr][cc] = true;
        queue<pair<int,int> > Queue;
        Queue.push({cr,cc});
        //this ans variable can be used to find out the
        //number of cells that are islands
        int ans = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int island = 1;
        while(!Queue.empty()){
            int x = Queue.front().first;
            int y = Queue.front().second;
            ans++;
            if(x==0 || y==0 || x==n-1 || y==m-1){
                island = 0;
            }
            Queue.pop();
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(isValid(newX,newY,n,m) && !visited[newX][newY] && grid[newX][newY]==0){
                    visited[newX][newY] = true;
                    Queue.push({newX,newY});
                }
            }
        }
        return island;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // print(grid);
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    ans+= bfsHelper(i,j,n,m,grid,visited);
                    
                }
            }
        }
        return ans;
    }
};