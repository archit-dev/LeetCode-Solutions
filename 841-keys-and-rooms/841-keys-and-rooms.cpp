class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        queue<int>Queue;
        Queue.push(0);
        int numberOfNodes=1;
        visited[0] = 1;
        while(!Queue.empty()){
            int node = Queue.front();
            Queue.pop();
            for(auto nbr:rooms[node]){
                if(!visited[nbr]){
                    Queue.push(nbr);
                    visited[nbr] = 1;
                    numberOfNodes++;
                }
            }
        }
        return numberOfNodes==n;
    }
};