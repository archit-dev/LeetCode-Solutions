class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones) pq.push(x);
        while(pq.size()!=0 && pq.size()!=1){
            int firstStone = pq.top();
            pq.pop();
            int secondStone = pq.top();
            pq.pop();
            if(firstStone!=secondStone) pq.push(abs(firstStone-secondStone));
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }
};