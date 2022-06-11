class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // 2 numbers that add to be divisible by k are K*x+r1 and K*y+r2
        //for this, r1 and r2 have the condition: r1+r2 == k
        //therefore the following cases arise:
        //1. freq[r1] == freq[k-r1]
        //2. freq[r1==0] ==> even
        //3. freq[r1==k/2] ==> even
        unordered_map<int,int>mp;
        for(int x:arr) mp[(x%k + k)%k]++;
        for(auto it:mp){
            if(it.first==0){
                if(it.second%2!=0) return false;
            }
            else if(k%2==0 && it.first==k/2){
                if(it.second%2!=0) return false;
            }
            else{
                if(it.second!=mp[k-it.first]) return false;
            }
        }
        return true;
    }
};