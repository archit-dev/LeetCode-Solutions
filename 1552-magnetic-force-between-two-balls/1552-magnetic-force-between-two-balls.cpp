class Solution {
public:
    bool canAllocate(vector<int>& positions,int m,int minDist){
        int lastBall = positions[0];
        int numBall = 1;
        for(int i=1;i<positions.size();i++){
            if(positions[i]-lastBall>=minDist){
                numBall++;
                lastBall = positions[i];
            }
            if(numBall==m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1, high = position[position.size()-1] - position[0];
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canAllocate(position,m,mid)){
                ans = max(ans,mid);
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};