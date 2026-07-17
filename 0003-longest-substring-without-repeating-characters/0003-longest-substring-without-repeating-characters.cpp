class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)return 0;
        vector<bool> visit(300, false);
        int result = 1;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(visit[(int)s[i]]){
                result = max(result, i - j);
                while(visit[(int)s[i]]){
                    visit[(int)s[j]] = false;
                    j++;
                }
            }
            visit[(int)s[i]] = true;
        }
        result = max(result, n - j);
        return result;
    }
};