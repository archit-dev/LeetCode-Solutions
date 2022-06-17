class Solution {
public:
    struct Orange{
        int x,y,time;
        Orange(int x_,int y_,int time_){
            x=x_;
            y=y_;
            time=time_;
        }
    };
    
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue< Orange >Queue;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) Queue.push(Orange(i,j,0));
            }
        }
        int timeAns = 0;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!Queue.empty()){
            Orange o = Queue.front();
            Queue.pop();
            for(int i=0;i<4;i++){
                int newX = o.x+dx[i];
                int newY = o.y+dy[i];
                int currTime = o.time;
                timeAns = max(timeAns,currTime);
                if(isValid(newX,newY,n,m) && grid[newX][newY]==1){
                    grid[newX][newY] = 2;
                    Queue.push(Orange(newX,newY,currTime+1));
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return timeAns;
    }
};