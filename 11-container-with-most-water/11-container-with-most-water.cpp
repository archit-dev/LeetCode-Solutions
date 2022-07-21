class Solution {
public:
    int maxArea(vector<int>& height) {
        //area = (min(left,right) * right-left+1)
        int left = 0 , right = height.size()-1;
        int area = 0;
        while(left<right){
            int tempArea = min(height[left],height[right]) * (right-left);
            area = max(area,tempArea);
            if(height[left]<height[right]) left+=1;
            else right-=1;
        }
        return area;
    }
};