class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        
        int low = 0, high = n1;
        while(low<=high){
            int cut1 = low + (high-low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int leftA = cut1>0 ? nums1[cut1-1] : INT_MIN;
            int leftB = cut2>0 ? nums2[cut2-1] : INT_MIN;
            int rightA = cut1<n1 ? nums1[cut1] : INT_MAX;
            int rightB = cut2<n2 ? nums2[cut2] : INT_MAX;
            
            if(leftA <= rightB && leftB <= rightA){
                if((n1+n2)%2==0){
                    return (max(leftA,leftB) + min(rightA,rightB))/2.0;
                }else{
                    return max(leftA,leftB);
                }
            }
            else if(leftA > rightB){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};