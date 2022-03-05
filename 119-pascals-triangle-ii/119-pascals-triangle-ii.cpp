class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector< vector<int> >triangles;
        for(int i=0;i<=rowIndex;i++){
            vector<int> temporary(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) temporary[j] = 1;
                else temporary[j] = triangles[i-1][j] + triangles[i-1][j-1];
            }
            triangles.push_back(temporary);
        }
        return triangles[rowIndex];
    }
};