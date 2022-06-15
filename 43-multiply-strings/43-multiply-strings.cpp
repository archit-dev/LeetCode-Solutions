class Solution {
private:
    string addNum(string num1,string num2){
        string ans = "";
        int ptr1 = num1.size()-1, ptr2 = num2.size()-1;
        int carry = 0;
        while(ptr1>=0 && ptr2>=0){
            int curr = (num1[ptr1]-'0') + (num2[ptr2]-'0') + carry; 
            carry = curr/10;
            int adder = curr%10;
            ans = to_string(adder)+ans;
            ptr1--;
            ptr2--;
        }
        while(ptr1>=0){
            int curr = (num1[ptr1]-'0') + carry; 
            carry = curr/10;
            int adder = curr%10;
            ans = to_string(adder)+ans;
            ptr1--;
        }
        while(ptr2>=0){
            int curr = (num2[ptr2]-'0') + carry; 
            carry = curr/10;
            int adder = curr%10;
            ans = to_string(adder)+ans;
            ptr2--;
        }
        if(carry) ans = to_string(carry) + ans;
        return ans;
    }
    
    string mult(string num,int mx,int placevalue){
        string ans = "";
        int carry = 0;
        for(int i=num.size()-1;i>=0;i--){
            int curr = (num[i]-'0')*mx+carry;
            carry = curr/10;
            int adder = curr%10;
            ans = to_string(adder)+ans;
        }
        if(carry) ans = to_string(carry)+ans;
        string zeros(placevalue,'0');
        ans+=zeros;
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string ans = "";
        int placeValue = 0;
        for(int i=num1.size()-1;i>=0;i--){
            int currNum = num1[i]-'0';
            string temp = mult(num2,currNum,placeValue);
            if(ans.size()==0) ans = temp;
            else ans = addNum(ans,temp);
            placeValue+= 1;
        }
        return ans;
    }
};