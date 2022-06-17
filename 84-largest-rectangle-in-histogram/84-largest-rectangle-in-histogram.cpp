class Solution {
    private:
    vector<int> NSL(vector<int>&heights){
        stack <int> st;
        vector<int>ans;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    
    vector<int> NSR(vector<int>&heights){
        stack <int> st;
        vector<int>ans(heights.size(),0);
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = heights.size();
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = NSL(heights);
        vector<int> nsr = NSR(heights);
        int ans = 0;
        vector<int>width(nsl.size(),1);
        for(int i=0;i<nsl.size();i++){
            width[i] = nsr[i]-nsl[i]-1;
            ans = max(ans,heights[i]*width[i]);
            // cout<<i<<" "<<width[i]<< " * "<<heights[i]<<" = "<<heights[i]*width[i]<<"\n";
        }
        return ans;
    }
};