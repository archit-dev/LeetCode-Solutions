class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> tempPair = intervals[0];
        vector<vector<int> > ans;
        for(int i=0;i<intervals.size();i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(tempPair[0]<=left && left<=tempPair[1]){
                //merge them
                tempPair[1] = max(right,tempPair[1]);
            }else{
                ans.push_back(tempPair);
                tempPair = intervals[i];
            }
        }
        ans.push_back(tempPair);
        return ans;
    }
};