class Solution {
public:
    bool isValid(int x,int y,int m,int n){
        if(x>=0 && x<m && y>=0 && y<n) return true;
        return false;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n=board[0].size();
        queue<pair<int,int>>Queue;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    if(i==0 || j==0 || i==m-1 || j==n-1){
                        board[i][j] = '#';
                        Queue.push({i,j});
                    }
                }
            }
        }
        
        int dx[4] ={-1,1,0,0};
        int dy[4] ={0,0,1,-1};

        while(!Queue.empty()){
            int x = Queue.front().first;
            int y = Queue.front().second;
            Queue.pop();
            
            for(int ind = 0;ind<4;ind++){
                int newX = x+dx[ind];
                int newY = y+dy[ind];
                if(isValid(newX,newY,m,n) && board[newX][newY]=='O'){
                    board[newX][newY] = '#';
                    Queue.push({newX,newY});
                }
            }
        }

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='#'){
                    board[row][col]='O';
                }else if(board[row][col]=='O'){
                    board[row][col] = 'X';
                }
            }
        }
    }
};