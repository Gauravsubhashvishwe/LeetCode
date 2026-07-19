class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
        }

        vector<bool> visit(26, false);
        string result;
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(visit[ch - 'a'])continue;

            while(!result.empty() && result.back() > ch && last[result.back() - 'a'] > i){
                visit[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            visit[ch - 'a'] = true;
        }
        return result;
    }
};