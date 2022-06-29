class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>&q,
             vector<vector<int>>&vis)
    {
        int dx[]={-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(isValid(newX,newY,heights.size(),heights[0].size()))
                {
                    if(vis[newX][newY]!=1 && heights[newX][newY]>=heights[x][y]){
                        q.push({newX,newY});
                        vis[newX][newY] = 1;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,-1));
        vector<vector<int>>atlantic(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    q.push({i,j});
                    pacific[i][j] = 1;
                }
            }
        }
        //bfs for pacific
        bfs(heights,q,pacific);
        //bfs for atlantic
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(j==m-1 || i==n-1){
                    q.push({i,j});
                    atlantic[i][j] = 1;
                }
            }
        }
        bfs(heights,q,atlantic);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    vector<int>temp(2);
                    temp[0] = i;
                    temp[1] = j;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};