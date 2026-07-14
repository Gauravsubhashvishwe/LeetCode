class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int j = -1;
        string result;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ' '){
                if(j != -1){
                    if(!result.empty()) result += ' ';
                    result += s.substr(i + 1, j - i);
                    j = -1;
                }
            }
            else{
                if(j == -1){
                    j = i;
                }
            }
        }
        if(j != -1){
            if(!result.empty()) result += ' ';
            result += s.substr(0, j + 1);
        }
        return result;
    }
};