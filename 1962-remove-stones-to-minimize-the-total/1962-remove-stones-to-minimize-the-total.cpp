class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<piles.size();i++){
            pq.push({piles[i],i});
        }
        
        while(k--){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            num-= num/2;
            pq.push({num,idx});
        }
        while(!pq.empty()){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            piles[idx] = num;
        }
        
        int sum = 0;
        for(int x:piles) sum+=x;
        return sum;
    }
};