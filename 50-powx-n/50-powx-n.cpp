class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        double ans = 1.0;
        long long nn = n;
        if(n<0) nn*=-1;
        while(nn){
            if(nn%2==0){
                x*=x;
                nn/=2;
            }else{
                ans*=x;
                nn-=1;
            }
        }
        return n<0 == true ? 1.0/ans : ans;
    }
};