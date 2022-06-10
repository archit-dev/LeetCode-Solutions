class Solution {
public:
    bool canEat(vector<int> piles,int k,int h){
        int time = 0, ptr = 0, n = piles.size();
        for(int i=0;i<n;i++){
            time+=piles[i]/k;
            if(piles[i]%k!=0)time+=1;
            if(time>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        // int high = *max_element(piles.begin(),piles.end());
        int high = INT_MAX;
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canEat(piles,mid,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};