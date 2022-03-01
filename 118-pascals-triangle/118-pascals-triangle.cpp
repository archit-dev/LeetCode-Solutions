class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //this vector of vectors will store all the levels of the Pascal's triangle
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            //we iterate from 1 till the number of rows there are in the triangle.
            //we can consider each iteration as the i'th level
            
            //at i-th level, the number of elements will be i
            //therefore we create a vector of length i
            vector<int> temp (i);
            
            //in order to fill the numbers of the i-th level
            //we will run a loop from j=0 till i-1, denoting 
            //the number at each index
            for(int j=0;j<i;j++){
                //clearly, the first and the last element will
                //always be 1, so use conditional statements to achieve that
                if(j==0 || j==i-1) temp[j] = 1;
                else{
                    //other than the first and the last elements,
                    //the rest of the entries of the triangle are the sum of the j-th and (j-1)th
                    //numbers from the previous level
                    temp[j] = ans[i-2][j] + ans[i-2][j-1];
                }
            }
            //push back the level into the answer vector
            ans.push_back(temp);
        }
        //return the answer vector
        return ans;
    }
};