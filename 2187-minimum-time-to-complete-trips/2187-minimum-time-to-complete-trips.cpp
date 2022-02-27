class Solution {
public:
    long long solve(vector<int>&time,int totalTrips,long long mid){
        long long trip=0;
        for(int i=0;i<time.size();i++)
        {
            trip+=(mid/time[i]);
            if(trip>=totalTrips)
            return 1;
        }
        return 0;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long trips = 0;
        long long sum=0;
        long long n = time.size();
        // vector<long long> dp(n,0);
        long long low = 0;
        long long high = LLONG_MAX;
        long long mid = low+(high-low)/2;
        long long ans = LLONG_MAX;
        while(low<=high){
            mid = low+(high-low)/2;
            long long x = solve(time,totalTrips,mid);
            if(x==1){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};