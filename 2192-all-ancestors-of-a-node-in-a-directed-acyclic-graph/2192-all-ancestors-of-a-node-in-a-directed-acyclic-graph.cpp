class Solution {
  public:
    void depthFirstSearch(vector < int > adjacencyList[], int currentNode, vector < int > & visitedNodes, vector < vector < int > > & ancestors, int originalParentNode) {
      visitedNodes[currentNode] = 1;
      for (auto it: adjacencyList[currentNode]) {
        if (!visitedNodes[it]) {
          ancestors[it].push_back(originalParentNode);
          depthFirstSearch(adjacencyList, it, visitedNodes, ancestors, originalParentNode);
        }
      }
    }
  vector < vector < int >> getAncestors(int n, vector < vector < int >> & edges) {
    vector < int > adjacencyList[n + 1];
    for (int i = 0; i < edges.size(); i++) {
      int start = edges[i][0];
      int end = edges[i][1];
      adjacencyList[start].push_back(end);
    }
    vector < int > visitedNodes(n, 0);
    vector < vector < int > > ancestors(n);
    for (int i = 0; i < n; i++) {
      depthFirstSearch(adjacencyList, i, visitedNodes, ancestors, i);
      for (int & node: visitedNodes) {
          node = 0;
      }
    }
    return ancestors;

  }
};