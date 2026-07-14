class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int n = s.size();
        int bal = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(bal > 0){
                    result += '(';
                }
                bal++;
            }
            else{
                bal--;

                if(bal > 0){
                    result += ')';
                }
            }
        }
        return result;
    }
};