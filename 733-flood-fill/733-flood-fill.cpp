class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    void helper(vector<vector<int>>&image,int x,int y, int newCol,int oldCol){
        image[x][y] = newCol;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int newX = dx[i] + x;
            int newY = dy[i] + y;
            if(isValid(newX,newY,image.size(),image[0].size()))
            {
                if(image[newX][newY]==oldCol){
                    helper(image,newX,newY,newCol,oldCol);
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m=image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor==color) return image;
        helper(image,sr,sc,color,originalColor);
        return image;
    }
};