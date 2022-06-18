class Solution {
public:
bool helper(vector<int>& weights,int days,int shipCapa){
    int numDays = 1;
    //i : 0->n 
    // weight[i] <= shipCapa --> load cargo into the ship shipCapa-=weight[i];
    // weight[i] > shipCapa --> we cannot load cargo , numDays +=1 , shipCapa
    // days == numDays -> return true, return false
    int capa = shipCapa;
    for(int indx=0;indx<weights.size();indx++){
        if(weights[indx]<=capa){
            capa-=weights[indx];
        }else{
            capa=shipCapa;
            numDays+=1;
            capa-=weights[indx];
        }
    }
    return numDays<=days;
}

int shipWithinDays(vector<int>& weights, int days){ 
    int lowerBound = *max_element(weights.begin(),weights.end());
    int upperBound = 0;
    for(int weight:weights) upperBound+=weight; 
    int ans = upperBound;
    while(lowerBound<=upperBound){
        int capacity = lowerBound + (upperBound-lowerBound)/2;// (l+u)/2 = l/2 + u/2 - l/2 +l/2
        if(helper(weights,days,capacity)){
            //returns true, if the allocation is successful
            ans = min(ans,capacity);
            //C ->succeessful
            //reduce the search space to left of C
            upperBound = capacity-1;   
        }else{
            lowerBound = capacity+1;
        }
    }
    return ans;
}


};