class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int n = columnTitle.size();
        int mul = 1;
        for(int i = 0; i < n; i++){
            result = result * 26 + (columnTitle[i] - 'A' + 1);
        }
        return result;
    }
};