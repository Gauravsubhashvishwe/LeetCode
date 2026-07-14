class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int result = 0;
        int bal = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') bal++;
            else if(s[i] == ')') bal--;
            result = max(result, bal);
        }
        return result;
    }
};