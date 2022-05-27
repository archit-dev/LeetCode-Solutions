class Solution {
public:
    bool detectCycleDFS(int node,vector<int>& visitedSoFar,
                       vector<int>& visitedOnThisPath, vector<int>graph[]){
        visitedSoFar[node] = 1;
        visitedOnThisPath[node] = 1;
        for(auto nbr:graph[node]){
            if(!visitedSoFar[nbr]){
                if(detectCycleDFS(nbr,visitedSoFar,visitedOnThisPath,graph)){
                    return true;
                }
            }
            else if(visitedSoFar[nbr] && visitedOnThisPath[nbr]){
                return true;
            }
        }
        visitedOnThisPath[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list first
        vector<int> graph[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            //b-->a
            graph[b].push_back(a);
        }
        vector<int> visitedSoFar(numCourses,0), visitedOnThisPath(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visitedSoFar[i]){
                if(detectCycleDFS(i,visitedSoFar,visitedOnThisPath,graph)){
                    // if there is a cycle, then courses cant be scheduled
                    return false;
                }
            }
        }
        return true;
    }
};