class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>prevStack,nextStack;
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        for(int i=0;i<n;i++){
            //find nsl
            while(prevStack.empty()==false && arr[prevStack.top()]>arr[i]){
                prevStack.pop();
            }
            if(!prevStack.empty()) left[i] = prevStack.top();
            prevStack.push(i);
        }
        for(int i=n-1;i>=0;i--){
            //find nsr
            while(nextStack.empty()==false && arr[nextStack.top()]>=arr[i]){
                nextStack.pop();
            }
            if(!nextStack.empty()) right[i] = nextStack.top();
            nextStack.push(i);
        }
        //now finding the subarrays : g1+1 X g2+1
        int ans = 0,mod = 1e9+7;
        for(int i=0;i<n;i++){
            int g1 = i - left[i] - 1;
            int g2 = right[i] - i - 1;
            //count = (g1+1)*(g2+1)
            long long count = ((g1+1)*(g2+1))%mod;
            count = ((count%mod)*(arr[i]%mod))%mod;
            ans = (ans + count)%mod;
        }
        return ans;
    }
};