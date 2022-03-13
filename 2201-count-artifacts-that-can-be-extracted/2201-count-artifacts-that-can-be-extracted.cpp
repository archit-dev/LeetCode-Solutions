class Solution {
  public:
    int digArtifacts(int n, vector < vector < int >> & artifacts, vector < vector < int >> & dig) {
      vector < vector < int > > board(n, vector < int > (n, -1));
      for (int i = 0; i < dig.size(); i++) {
        int digRow = dig[i][0];
        int digCol = dig[i][1];
        board[digRow][digCol] = 0;
      }
      int numberOfArtifacts = 0;
      for (int i = 0; i < artifacts.size(); i++) {
        int startRow = artifacts[i][0];
        int startCol = artifacts[i][1];
        int endRow = artifacts[i][2];
        int endCol = artifacts[i][3];
        bool noObjections = true;
        for (int j = startRow; j <= endRow; j++) {
          for (int k = startCol; k <= endCol; k++) {
            if (board[j][k] == -1) {
              noObjections = false;
              break;
            }
          }
          if (!noObjections) break;
        }
        if (noObjections) numberOfArtifacts++;
      }
      return numberOfArtifacts;
    }
};