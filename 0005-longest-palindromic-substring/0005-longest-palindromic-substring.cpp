class Solution {
    int n;
    int helper(int srt, int lst, string &s){
        while(srt >= 0 && lst < n && s[srt] == s[lst]){
            srt--;
            lst++;
        }
        return lst - srt - 1;
    }
public:
    string longestPalindrome(string s) {
        n = s.size();
        if(n == 0)return "";
        int maxl(0), srt(0);
        for(int i = 0; i < n; i++){
            int len1 = helper(i, i, s);
            int len2 = helper(i, i + 1,s);
            int len = max(len1, len2);
            if(len > maxl){
                maxl = len;
                srt = i - (len - 1) / 2;
            }
        }
        return s.substr(srt, maxl);
    }
};