class Solution {
public:
    struct num{
      int si,ei,freq;
        num(int si_,int ei_,int freq_){
            si = si_;
            ei = ei_;
            freq = freq_;
        }
    };
    int findShortestSubArray(vector<int>& nums) {
        map<int,num*>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                num* newNum = new num(i,i,1);
                mp[nums[i]] = newNum;
            }else{
                mp[nums[i]]->ei = i;
                mp[nums[i]]->freq +=1;
            }
        }
        int maxFreq = 0;
        for(auto it:mp) maxFreq = max(maxFreq,it.second->freq);
        vector<int>vec;
        for(auto it:mp){
            if(maxFreq==it.second->freq){
                vec.push_back(it.first);
            }
        }
        int minLen = INT_MAX;
        for(int x:vec){
            minLen = min(minLen,mp[x]->ei-mp[x]->si+1);
        }
        return minLen;
    }
};