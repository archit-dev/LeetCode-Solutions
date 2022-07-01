class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1]!=b[1]) return a[1]>b[1];
        return a[0]>b[0];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0 ;
        int size = 0;
        for(int i=0;i<boxTypes.size();i++){
            int temp = boxTypes[i][0] <= truckSize ? boxTypes[i][0] : truckSize;
            truckSize-=temp;
            temp *= boxTypes[i][1];
            ans+=temp;
            if(truckSize==0) break;
        }
        return ans;
    }
};