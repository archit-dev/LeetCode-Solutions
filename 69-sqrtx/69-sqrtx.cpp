class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int i;
        for(i=2;(long long)i*i<=x;i++){
            if(i*i==x) return i;
        }
        return i-1;
    }
};