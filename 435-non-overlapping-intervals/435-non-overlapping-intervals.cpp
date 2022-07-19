class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 0;
        int n = intervals.size();
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            if(currStart>=end){
                //no overlap
                end = currEnd;
            }
            else{
                //overlap
                count+=1;
                end = min(end,currEnd);
            }
        }
        return count;
    }
};