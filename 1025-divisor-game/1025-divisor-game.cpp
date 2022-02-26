class Solution {
public:
    bool solve(int n,int currentPlayer){
        if(n==1 && currentPlayer==0) return false;
        if(n==1 && currentPlayer==1) return true; 
        bool ans = false;
        int newPlayer = currentPlayer == 0 ? 1 : 0 ;
        ans = solve(n-1,newPlayer);
        return ans;
    }
    
    bool divisorGame(int n) {
        //if n==0 and current chance is Alice, its a loss
        //otherwise its a win 
        return solve(n,0);
    }
};