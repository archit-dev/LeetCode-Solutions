class Solution {
public:
    bool canEat(vector<int>& piles,int h,int k){
        int time = 0;
        for(int i=0;i<piles.size();i++){
            time += piles[i]/k;
            if(piles[i]%k!=0) time+=1;
            if(time>h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canEat(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};