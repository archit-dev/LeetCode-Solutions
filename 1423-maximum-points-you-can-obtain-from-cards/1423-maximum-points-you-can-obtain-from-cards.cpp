class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int reqSize = n-k;
        long long sum = 0,finalAns = INT_MAX;
        int low = 0 , high = 0 ;
        while(high<n){
            if(high-low==reqSize)
            {
                sum-=cardPoints[low];
                low+=1;
            }
            sum+=cardPoints[high];
            if(high>=reqSize-1){
                finalAns = min(sum,finalAns);
            }
            high++;
        }
        sum = 0;
        for(int x:cardPoints) sum+=x;
        return sum-finalAns;
    }
};