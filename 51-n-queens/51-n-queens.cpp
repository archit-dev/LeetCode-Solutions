class Solution {
private:
    bool isSafe(int cr,int cc,int n,vector<string>& board){
        //we need check diagonally up towards right and left and directly up
        int copyCr = cr, copyCc = cc;
        //diagonally left upwards
        while(cr>=0 && cc>=0){
            if(board[cr][cc]=='Q') return false;
            cr--;
            cc--;
        }
        cr = copyCr;
        cc = copyCc;
        //diagonally right upwards
        while(cr>=0 && cc<n){
            if(board[cr][cc]=='Q') return false;
            cr--;
            cc++;
        }
        cr = copyCr;
        cc = copyCc;
        //stright upwards
        while(cr>=0){
            if(board[cr][cc]=='Q') return false;
            cr--;
        }
        return true;
    }
        
    void solve(int currentRow,int n,vector<string>& board,
               vector<vector<string>>& allBoards)
    {
        if(currentRow==n){
            allBoards.push_back(board);
            return;
        }
        for(int col=0; col<n;col++){
            if(isSafe(currentRow,col,n,board)){
                board[currentRow][col] = 'Q';
                solve(currentRow+1,n,board,allBoards);
                board[currentRow][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > allBoards;
        string temp(n,'.');
        vector<string>board(n,temp);
        solve(0,n,board,allBoards);
        return allBoards;
    }
};