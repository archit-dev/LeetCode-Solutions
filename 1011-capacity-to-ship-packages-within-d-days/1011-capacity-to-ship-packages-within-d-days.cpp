class Solution {
public:
    bool canHoldAll(int weight,vector<int>& weights,int days){
        int currentWeight = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+currentWeight<=weight){
                currentWeight+=weights[i];
            }else{
                days-=1;
                currentWeight = weights[i];
            }
            if(days==0) return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int x:weights) high+=x;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canHoldAll(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};