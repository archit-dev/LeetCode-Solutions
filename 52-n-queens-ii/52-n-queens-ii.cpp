class Solution {
public:
    bool isSafe(vector<vector<int> >& board,int cr,int cc,int n){
        int dcr = cr, dcc = cc;
        //check up
        while(cr>=0){
            if(board[cr][cc]==1) return false;
            cr--;
        }
        cr = dcr;
        //check up-left
        while(cr>=0 && cc>=0){
            if(board[cr][cc]==1) return false;
            cr--;
            cc--;
        }
        cr=dcr;
        cc=dcc;
        //check up right
        while(cr>=0 && cc<n){
            if(board[cr][cc]==1) return false;
            cr--;
            cc++;
        }
        return true;
    }
    
    int solve(vector<vector<int> >& board,int cr,int n){
        if(cr==n){
            return 1;
        }
        int ans = 0;
        for(int cc=0;cc<n;cc++){
            if(isSafe(board,cr,cc,n)){
                board[cr][cc] = 1;
                ans+= solve(board,cr+1,n);
                board[cr][cc] = 0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int> >board(n,vector<int>(n,0));
        count+=solve(board,0,n);
        return count;
    }
};