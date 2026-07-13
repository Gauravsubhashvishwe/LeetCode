class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        map<int, int> srt;
        map<int, int> lst;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            srt[s[i]]++;
            lst[t[i]]++;
        }

        map<int, int>::iterator it, jt;
        it = srt.begin();
        jt = lst.begin();
        for(; it != srt.end() && jt != lst.end(); it++, jt++){
            if(it->first == jt->first && it->second == jt->second)continue;
            else return false;
        }
        return true;
    }
};