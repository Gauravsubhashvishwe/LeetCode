class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        int result = 0;
        int neg = -1;
        for(; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(neg == -1){
                    neg = 0;
                }
                int digit = s[i] - '0';
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                    return (neg == 0) ? INT_MAX : INT_MIN;
                }
                result *= 10;
                result += digit;
            }
            else if(neg == -1 && s[i] == '-'){
                neg = 1;
            }
            else if(neg == -1 && s[i] == '+'){
                neg = 0;
            }
            else break;
        }
        if(neg == 1){
            result *= -1;
        }
        return result;
    }
};