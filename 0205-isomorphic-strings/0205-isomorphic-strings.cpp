class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())return false;

        int n = s.size();
        map<char, char> mp;
        map<char, char> rev;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) == mp.end() && rev.find(t[i]) == rev.end()){
                mp[s[i]] = t[i];
                rev[t[i]] = s[i];
            }
            else if(mp.find(s[i]) == mp.end() || rev.find(t[i]) == rev.end()){
                return false;
            }
            else{
                if(mp[s[i]] == t[i] && rev[t[i]] == s[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};