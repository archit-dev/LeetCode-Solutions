class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int x:arr){
            mp[(x%k+k)%k]+=1;
        }
        for(auto it:mp){
            int num1 = it.first;
            if(num1==0){
                if(it.second%2!=0) return false;
            }
            else if(k%2==0 && num1==k/2){
                if(it.second%2!=0) return false;
            }
            else{
                if(it.second!=mp[k-num1]) return false;
            }
        }
        return true;
    }
};