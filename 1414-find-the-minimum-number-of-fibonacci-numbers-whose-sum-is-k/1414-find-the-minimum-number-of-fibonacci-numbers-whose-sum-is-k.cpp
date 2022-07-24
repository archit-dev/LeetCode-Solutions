class Solution {
private:
    int search(vector<int>& fib,int tgt){
        int low = 0, high = fib.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(fib[mid]==tgt) return tgt;
            else if(fib[mid]<tgt){
                ans = fib[mid];
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
    
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        int f1 = 1, f2 = 1;
        fib.push_back(f1);
        fib.push_back(f2);
        int temp = 0;
        while(temp<k){
            temp = f1+f2;
            fib.push_back(temp);
            if(temp>=k) break;
            f1 = f2;
            f2 = temp;
        }
        int ans = 0;
        while(k){
            int num = search(fib,k);
            ans+=1;
            k-=num;
        }
        return ans;
    }
};