class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    bool helper(vector<vector<char>>& board,string word,int cr,int cc,int ptr){
        if(ptr==word.size()) return true;
        char curr = board[cr][cc];
        board[cr][cc]='.';
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int ind=0;ind<4;ind++){
            int newX = dx[ind]+cr;
            int newY = dy[ind]+cc;
            if(isValid(newX,newY,board.size(),board[0].size()) && board[newX][newY]!='.'
              && board[newX][newY]==word[ptr])
            {
                if(helper(board,word,newX,newY,ptr+1)) return true;
            }
        }
        board[cr][cc]=curr;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ptr = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(helper(board,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};