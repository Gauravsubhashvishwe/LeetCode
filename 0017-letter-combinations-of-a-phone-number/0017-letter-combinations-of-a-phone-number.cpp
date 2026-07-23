class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result = {""};
        vector<string> maping {"","","abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
        int n  = digits.size();
        for(int i = 0; i < n; i++){
            int m = result.size();
            for(int j = m - 1; j >= 0; j--){
                string curr = result[j];
                result.erase(result.begin() + j);
                for(char to_a : maping[digits[i] - '0']){
                    result.push_back(curr + to_a);
                }
            }
        }
        return result;
    }
};