class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr = 1;
        int d = target.size();
        int lastEle = target[d-1];
        int ptr = 0;
        vector<string>ans;
        while(curr<=lastEle){
            ans.push_back("Push");
            if(curr!=target[ptr]){
                ans.push_back("Pop");
            }else{
                ptr++;
            }
            curr++;
        }
        return ans;
    }
};