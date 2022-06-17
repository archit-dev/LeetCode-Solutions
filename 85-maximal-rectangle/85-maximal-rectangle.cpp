class Solution {
public:
    int MaxAreaHistogram(vector<int>& heights){
        int n = heights.size();
        vector<int>left(n,-1),right(n,n);
        stack<pair<int,int>>st;
        //nsl
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(!st.empty()) left[i] = st.top().second;
            st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        //nsr
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }
            if(!st.empty()) right[i] = st.top().second;
            st.push({heights[i],i});
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
            ans = max(ans,heights[i]*width);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }else{
                    heights[j] = 0;
                }
            }
            ans = max(ans,MaxAreaHistogram(heights));
        }
        return ans;
    }
};