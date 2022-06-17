class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(dq.empty()==false && dq.front()==i-k) dq.pop_front();
            
            int currentNum = nums[i];
            //pop all the smaller elements from the back of the que
            while(dq.empty()==false && nums[dq.back()]<currentNum){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};