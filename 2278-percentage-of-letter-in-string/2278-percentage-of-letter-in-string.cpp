class Solution {
  public:
    int percentageLetter(string s, char letter) {
      int n = s.size();
      int count = 0;
      for (char x: s) {
        if (x == letter) {
          count++;
        }
      }
      return round(count * 100 / n);
    }
};