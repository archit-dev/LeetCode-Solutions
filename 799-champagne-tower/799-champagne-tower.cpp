class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0) return 0.0;
        vector< vector<double> > tower(101,vector<double>(101,0.0));
        tower[0][0] = (double)poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(tower[i][j]>=1){
                    tower[i+1][j] += (tower[i][j]-1)/2.0;
                    tower[i+1][j+1] += (tower[i][j]-1)/2.0;
                    tower[i][j] = 1.0;
                }
            }
        }
        // for(int i=0;i<tower.size();i++){
        //     for(int j=0;j<tower[i].size();j++){
        //         cout<<tower[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return tower[query_row][query_glass];
    }
};