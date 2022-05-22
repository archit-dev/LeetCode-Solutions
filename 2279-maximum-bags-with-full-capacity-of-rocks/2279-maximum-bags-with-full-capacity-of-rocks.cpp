class Solution {
  public:
    int maximumBags(vector < int > & capacity, vector < int > & rocks, int additionalRocks) {
      int n = capacity.size();
      vector < int > remainderStones(n, 0);
      for (int i = 0; i < n; i++) {
        remainderStones[i] = capacity[i] - rocks[i];
      }
      sort(remainderStones.begin(), remainderStones.end());
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (remainderStones[i] == 0) {
          ans++;
        } else {
          int stonesRequired = remainderStones[i];
          if (additionalRocks >= stonesRequired) {
            additionalRocks -= stonesRequired;
            ans++;
          }
        }
      }
      return ans;
    }
};