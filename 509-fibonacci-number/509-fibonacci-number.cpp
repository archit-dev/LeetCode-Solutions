class Solution {
public: 
    int fib(int n) {
        int prev2 = 0;
        int prev = 1;
        if(n==0||n==1){
            return n;
        }
        int curr = 0;
        for(int i = 2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};