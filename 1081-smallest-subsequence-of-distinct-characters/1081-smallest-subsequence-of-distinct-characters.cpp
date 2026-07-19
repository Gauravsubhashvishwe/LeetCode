class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,-1);
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }
        
        vector<bool> visit(26, false);
        string result;

        for(int i = 0; i < s.size(); i++){
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