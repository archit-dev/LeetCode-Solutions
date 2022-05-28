// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    private:
    struct point{
        int x,y,steps;
        point(int x_,int y_,int steps_){
            x=x_;
            y=y_;
            steps=steps_;
        }
    };
    
    bool isValid(int x,int y,int n){
        if(x>=1 && x<n && y>=1 && y<n) return true;
        return false;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int> > board(N+1,vector<int>(N+1,0));
	    queue<point>Queue; 
	    Queue.push(point(KnightPos[0],KnightPos[1],0));
	    board[KnightPos[0]][KnightPos[1]] = 1;
	    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
	    int dy[8] = {1,-1,1,-1,2,-2,2,-2};
	    while(!Queue.empty()){
	        int x = Queue.front().x;
	        int y = Queue.front().y;
	        int steps = Queue.front().steps;
	        if(x==TargetPos[0] && y==TargetPos[1]) return steps;
	        Queue.pop();
	        for(int ind=0;ind<8;ind++){
	            int newX = x+dx[ind];
	            int newY = y+dy[ind];
	            if(isValid(newX,newY,N+1) && board[newX][newY]!=1){
	                board[newX][newY] = 1;
	                Queue.push(point(newX,newY,steps+1));
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends