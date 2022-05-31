class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    int bfsHelper(int cr,int cc,int n,int m,vector<vector<int> > & grid,
                 vector<vector<bool> > & visited)
    {
        visited[cr][cc] = true;
        queue<pair<int,int> >Queue;
        Queue.push({cr,cc});
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int islandSize = 0;
        while(!Queue.empty()){
            int x = Queue.front().first;
            int y = Queue.front().second;
            Queue.pop();
            islandSize++;
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(isValid(newX,newY,n,m) && grid[newX][newY] == 1 
                   && visited[newX][newY]==false)
                {
                    visited[newX][newY] = true;
                    Queue.push({newX,newY});
                }
            }
        }
        return islandSize;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int temp = bfsHelper(i,j,n,m,grid,visited);
                    maxArea=max(maxArea,temp);
                }
            }
        }
        return maxArea;
    }
};