class Solution {
public:
    double average(vector<int>& salary) {
        int min_ = INT_MAX;
        int max_ = INT_MIN;
        for(int &x:salary){
            min_ = min(min_,x);
            max_ = max(max_,x);
        }
        double ans = 0.0;
        double len = 0.0;
        for(int &x:salary){
            double curr = (double)x;
            if(x!=min_ && x!=max_) {
                ans+=curr;
                len++;
            }
        }
        return ans/len;
    }
};