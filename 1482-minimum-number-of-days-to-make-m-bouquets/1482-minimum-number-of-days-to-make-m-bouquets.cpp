class Solution {
public:
    bool isValid(int limit, vector<int>& bloomDay,int m,int k){
        int size = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=limit){
                size+=1;
            }else{
                size = 0;
            }
            if(size==k){
                size=0;
                m-=1;
            }
            if(m==0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        if(m*k>bloomDay.size()) return ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isValid(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};