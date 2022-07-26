class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target>1 && maxDoubles>0){
            if(target%2==0 && maxDoubles!=0){
                steps+=1;
                target/=2;
                maxDoubles -=1;
            }
            else{
                steps+=1;
                target-=1;
            }
        }
        return steps + target-1;
    }
};