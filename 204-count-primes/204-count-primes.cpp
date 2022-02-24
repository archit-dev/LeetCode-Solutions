class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return false;
        vector<bool> isPrime(n+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(!isPrime[i]) continue;
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};