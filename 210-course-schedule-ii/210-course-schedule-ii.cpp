class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list first
        vector<int> graph[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            //b-->a
            graph[b].push_back(a);
        }
        vector<int>indegree(numCourses,0);
        for(int node = 0 ; node<numCourses;node++){
            for(auto nbr:graph[node]){
                indegree[nbr]++;
            }
        }
        queue<int>Queue;
        for(int node=0;node<numCourses;node++){
            if(indegree[node]==0) Queue.push(node);
        }
        vector<int> topoSort;
        while(!Queue.empty()){
            int node = Queue.front();
            Queue.pop();
            topoSort.push_back(node);
            //now subtract the indegree of the nbrs
            for(auto nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) Queue.push(nbr);
            }
        }
        if(topoSort.size()!=numCourses) return vector<int>(0);
        return topoSort;
    }
};