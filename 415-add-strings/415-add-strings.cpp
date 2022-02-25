class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int carry = 0;
        string ans = "";
        while(n1>=0 && n2>=0){
            int firstNum = num1[n1]-'0';
            int secondNum = num2[n2]-'0';
            int sum = (firstNum+carry+secondNum)%10;
            carry = (firstNum+carry+secondNum)/10;
            // cout<<firstNum<<" "<<secondNum<<" "<<sum<<" "<<carry<<"\n";
            ans = to_string(sum)+ans;
            n1--;
            n2--;
        }
        while(n1>=0){
            int firstNum = num1[n1]-'0';
            int sum = (firstNum+carry)%10;
            carry = (firstNum+carry)/10;
            ans = to_string(sum)+ans;
            n1--;
        }
        while(n2>=0){
            int firstNum = num2[n2]-'0';
            int sum = (firstNum+carry)%10;
            carry = (firstNum+carry)/10;
            ans = to_string(sum)+ans;
            n2--;
        }
        if(carry==1) ans = "1" + ans;
        return ans;
    }
};