class Solution {
public:
    bool checkRow(vector<vector<char>>& board,int row){
        unordered_map<char,int> mp;
        for(int i=0;i<9;i++){
            if(board[row][i]!='.') mp[board[row][i]]+=1;
        }
        for(auto it:mp){
            if(it.second>1) return false;
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board,int col){
        unordered_map<char,int> mp;
        for(int i=0;i<9;i++){
            if(board[i][col]!='.') mp[board[i][col]]+=1;
        }
        for(auto it:mp){
            if(it.second>1) return false;
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board,int row,int col){
        unordered_map<char,int> mp;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]!='.') mp[board[i][j]]+=1;
            }
        }
        for(auto it:mp){
            if(it.second>1) return false;
        }
        return true;
    }
        
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!checkRow(board,i)) return false;
            for(int j=0;j<9;j++){
                if(!checkCol(board,j)) return false;
            }
        }
        int dx[9] = {0,0,0,3,3,3,6,6,6};
        int dy[9] = {0,3,6,0,3,6,0,3,6};
        for(int i=0;i<9;i++){
            if(!checkBox(board,dx[i],dy[i])) return false;
        }
        return true;
    }
};