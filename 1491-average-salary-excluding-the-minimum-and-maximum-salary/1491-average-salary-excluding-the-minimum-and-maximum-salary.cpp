class Solution {
public:
    double average(vector<int>& salary) {
        int min_ = INT_MAX;
        int max_ = INT_MIN;
        int ans = 0;
        for(int &x:salary){
            min_ = min(min_,x);
            max_ = max(max_,x);
            ans += x;
        }
        return (double)(ans-min_-max_)/(double)(salary.size()-2);
       
    }
};