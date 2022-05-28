class Solution {
private:
    struct cell{
        int x,y,color;
        cell(int x_,int y_,int color_){
            x=x_;
            y=y_;
            color=color_;
        }
    };
    
    bool isValid(int x,int y,int n,int m){
        if(x<n && x>=0 && y>=0 && y<m) return true;
        return false;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<cell>Queue;
        int n = image.size();
        int m = image[0].size();
        Queue.push(cell(sr,sc,newColor));
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        if(newColor==oldColor) return image;
        while(!Queue.empty()){
            int x = Queue.front().x;
            int y = Queue.front().y;
            int color = Queue.front().color;
            Queue.pop();
            for(int ind=0;ind<4;ind++){
                int newX = x+dx[ind];
                int newY = y+dy[ind];
                if(isValid(newX,newY,n,m) && image[newX][newY]==oldColor){
                    Queue.push(cell(newX,newY,newColor));
                    image[newX][newY] = newColor;
                }
            }
        }
        return image;
    }
};