class Solution {
  public:
    int gcd(int a, int b) {
      if (a == 0)
        return b;
      return gcd(b % a, a);
    }
    
  pair < int, int > recudeSlopes(int y, int x) {
    int gcdd = gcd(abs(y), abs(x));
    bool signOfSlope = (y < 0) ^ (x < 0);
    if (signOfSlope)
      return make_pair(-abs(y) / gcdd, abs(x) / gcdd);
    else
      return make_pair(abs(y) / gcdd, abs(x) / gcdd);
  }
  
  int minimumLines(vector < vector < int >> & stockPrices) {
    sort(stockPrices.begin(), stockPrices.end());
    int numberOfLines = 0;
    int prevYDiff = INT_MIN;
    int prevXDiff = INT_MIN;
    for (int i = 1; i < stockPrices.size(); i++) {
      pair < int, int > pairOfDiff = recudeSlopes(stockPrices[i][1] - stockPrices[i - 1][1], (stockPrices[i][0] - stockPrices[i - 1][0]));
      if (prevYDiff == pairOfDiff.first && prevXDiff == pairOfDiff.second) {
        continue;
      } else {
        prevYDiff = pairOfDiff.first;
        prevXDiff = pairOfDiff.second;
        numberOfLines++;
      }

    }
    return numberOfLines;
  }
};