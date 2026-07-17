class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows,"");
        int n = s.size();
        int i = 0;
        while(i < n){
            int j = 0;
            while(j < numRows && i < n){
                result[j].push_back(s[i]);
                j++;
                i++;
            }
            j -= 2;
            while(j > 0 && i < n){
                result[j].push_back(s[i]);
                j--;
                i++;
            }
        }
        for(i = 1; i < numRows; i++){
            result[0] += result[i];
        }
        return result[0];
    }
};