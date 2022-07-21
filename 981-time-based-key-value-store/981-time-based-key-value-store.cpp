class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>dataStore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dataStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int reqIndex = -1;
        
        int n = dataStore[key].size();
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(dataStore[key][mid].first==timestamp){
                reqIndex = mid;
                break;
            }
            else if(dataStore[key][mid].first<timestamp){
                reqIndex = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(reqIndex!=-1) ans = dataStore[key][reqIndex].second;
        return ans;
    }
};
