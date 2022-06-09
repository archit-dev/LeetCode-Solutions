class Solution {
public:
    int helper(vector<string>& arr,vector<int>& count,int idx,int currLen){
        if(idx==arr.size()) return currLen;
        
        string currStr = arr[idx];
        vector<int>selfCheck(26,0);
        
        for(char x:currStr){ 
            if(count[x-'a']!=0 || selfCheck[x-'a']!=0){
                //if the current string has a repeating character
                //just ignore and move forward
                return helper(arr,count,idx+1,currLen);
            }
            selfCheck[x-'a']+=1;
        }
        //otherwise you have 2 options, either include this string or exclude it
        
        //for including, mark the freq of characters in count arr
        for(char x:currStr) count[x-'a']+=1;
        int include = helper(arr,count,idx+1,currLen+currStr.size());
        
        //for excluding, remove the freq of characters in count arr
        for(char x:currStr) count[x-'a']-=1;
        int exclude = helper(arr,count,idx+1,currLen);
        
        return max(include,exclude);
    }
    
    int maxLength(vector<string>& arr) {
        vector<int>count(26,0);
        return helper(arr,count,0,0);
    }
};