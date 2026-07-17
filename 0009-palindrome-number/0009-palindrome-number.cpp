class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int num = x;
        int result = 0;
        while(x > 0){
            int front = (x % 10);
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && front > 7))return false;
            result = result * 10 + front;
            x /= 10;
        }
        return num == result;
    }
};