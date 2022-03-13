class Solution {
  public:
    int maximumTop(vector < int > & nums, int k) {
      int n = nums.size();

      if (n == 1 && k % 2 != 0) return -1; 
        
      if (k == 1) return nums[1];

      if (k == 0) return nums[0];


      if (k <= n) {
        priority_queue < int > maxPriorityQueue;
        int pointerOfArray = 0;
        for (int i = 1; i < k; i++) {
          maxPriorityQueue.push(nums[pointerOfArray++]);
        }
        return max(maxPriorityQueue.top(), nums[pointerOfArray + 1]);
      } else {
        priority_queue < int > maxPriorityQueue;
        int pointerOfArray = 0;
        while (pointerOfArray != n) {
          maxPriorityQueue.push(nums[pointerOfArray]);
          k--;
          pointerOfArray++;
        }
        if (k % 2 != 0) {
          return maxPriorityQueue.top();
        } else {
          if (maxPriorityQueue.size() >= 2) return maxPriorityQueue.top();
          else return -1;
        }
      }
      return -1;
    }
};