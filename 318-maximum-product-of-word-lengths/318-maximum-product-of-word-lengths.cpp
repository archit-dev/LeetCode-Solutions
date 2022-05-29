class Solution {
public:
    bool notSame(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]!=0 && b[i]!=0) return false;
        }
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<vector<int> > vec(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(char x:words[i]){
                vec[i][x-'a']++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(notSame(vec[i],vec[j])){
                        int temp = words[i].size()*words[j].size();
                        ans=max(ans,temp);
                    }
                }
            }
        }
        return ans;
    }
};