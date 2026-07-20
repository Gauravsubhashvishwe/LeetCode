class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        vector<int> result(n, 0);
        for(int i = n - 1; i >= 0; i--){
            int d = digits[i];
            result[i] = (d + c) % 10;
            c = (d + c) / 10;
        }
        if(c == 1){
            result.insert(result.begin(), 1);
        }
        return result;
    }
};