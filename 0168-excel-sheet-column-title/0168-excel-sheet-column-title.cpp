class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string result;
        while(n > 0){
            n--;
            result += ('A' + (n % 26 ));
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};