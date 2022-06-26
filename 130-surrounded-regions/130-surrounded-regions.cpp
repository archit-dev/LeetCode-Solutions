class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    void dfsBoundary(vector<vector<char>>& board,int x,int y){
        board[x][y] = '#';
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int newX = dx[i]+x;
            int newY = dy[i]+y;
            if(isValid(newX,newY,board.size(),board[0].size()))
            {
                if(board[newX][newY]=='O'){
                    dfsBoundary(board,newX,newY);
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0 || i==n-1 ||j==m-1){
                    //boundary
                    if(board[i][j]=='O'){
                        dfsBoundary(board,i,j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};