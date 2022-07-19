class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int cumSum = 0, ans = 0;
        for(int i=n-1;i>=0;i--){
            cumSum+=satisfaction[i];
            if(cumSum+ans<ans){
                break;
            }
            ans+=cumSum;
        }
        return ans;
    }
};