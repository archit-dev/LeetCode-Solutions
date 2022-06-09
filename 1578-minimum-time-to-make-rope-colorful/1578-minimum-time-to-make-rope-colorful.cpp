class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int low = 0, high = 1;
        int ans = 0;
        while(high<colors.size()){
            if(colors[low]==colors[high]){
                ans+= min(neededTime[low],neededTime[high]);
                if(neededTime[low]<neededTime[high]) low = high;
                high++;
            }else{
                low = high;
                high++;
            }
        }
        return ans;
    }
};