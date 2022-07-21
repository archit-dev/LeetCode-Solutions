class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>>rows;
        unordered_map<int,unordered_set<int>>cols;
        map<pair<int,int>,unordered_set<int>>squares;
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }
                
                char curr = board[r][c];
                if(rows[r].find(curr)!=rows[r].end() ||
                   cols[c].find(curr)!=cols[c].end() || 
                   squares[{r/3,c/3}].find(curr)!=squares[{r/3,c/3}].end())
                {
                    return false;
                }
                
                rows[r].insert(curr);
                cols[c].insert(curr);
                squares[{r/3,c/3}].insert(curr);
            }
        }
        
        return true;
    }
};