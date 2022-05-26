class Solution {
public:
    struct height{
        int x;
        int y;
        int hi;
        height(int x_,int y_,int hi_){
            x=x_;
            y=y_;
            hi=hi_;
        }
    };
    
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>heightMatrix(n,vector<int>(m,-1));
        queue<height>Queue;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //if its a water cell, add it to the queue
                //with height = 0
                if(isWater[i][j]==1){
                    Queue.push(height(i,j,0));
                    heightMatrix[i][j] = 0;
                }
            }
        }
        //start the DFS similar to the rotten oranges question
        while(!Queue.empty()){
            int x = Queue.front().x;
            int y = Queue.front().y;
            int h = Queue.front().hi;
            Queue.pop();
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int newX = x+dx[i] , newY = y+dy[i];
                if(isValid(newX,newY,n,m) && heightMatrix[newX][newY]==-1){
                    heightMatrix[newX][newY] = h+1;
                    Queue.push(height(newX,newY,heightMatrix[newX][newY]));
                }
            }
        }
        return heightMatrix;
    }
};