class Solution {
public:
    double helper(double x,long long n){
        if(n==0) return 1.0;
        double ans = 1.0;
        if(n%2==1){
            ans *= x;
            n-=1;
        }
        ans *= helper(x*x,n/2);
        return ans;
    }
    double myPow(double x, int n) {
        if(n<0) return 1.0/helper(x,-1LL*n);
        else return helper(x,n);
    }
};