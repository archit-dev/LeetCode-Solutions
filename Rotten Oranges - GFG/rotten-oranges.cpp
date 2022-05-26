// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    struct orange{
        int x;
        int y;
        int t;
        orange(int x_,int y_,int t_){
            x=x_;
            y=y_;
            t=t_;
        }
    };
    public:
    bool isValid(int newX,int newY,int n,int m){
        if(newX>=0 && newX<n && newY>=0 && newY<m)
            return true;
        return false;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<orange>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //insert all the rotten oranges to the queue
                //at time = 0
                if(grid[i][j]==2){
                    q.push(orange(i,j,0));
                }
            }
        }
        //now start the bfs
        int requiredTime = -1;
        while(!q.empty()){
            orange curr = q.front();
            q.pop();
            int x = curr.x;
            int y = curr.y;
            int t = curr.t;
            int x_[4] = {0,-1,0,1};
            int y_[4] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int newX = x + x_[i];
                int newY = y + y_[i];
                if(isValid(newX,newY,n,m) && grid[newX][newY]==1){
                    //rotten that orange
                    grid[newX][newY] = 2;
                    q.push(orange(newX,newY,t+1));
                    requiredTime=t+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return requiredTime;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends