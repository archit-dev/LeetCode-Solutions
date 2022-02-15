class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1||n==2){
            return n==0 ? 0 : 1;
        }
        int curr3 = 0;
        int curr2 = 1;
        int curr1 = 1;
        for(int i=3;i<=n;i++){
            int ans = curr1+curr2+curr3;
            curr3 = curr2;
            curr2 = curr1;
            curr1 = ans;
        }
        return curr1;
    }
};