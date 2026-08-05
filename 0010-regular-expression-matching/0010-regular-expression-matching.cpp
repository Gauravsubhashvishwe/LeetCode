class Solution {
    int helper(int n, int m, string &s, string &p, vector<vector<int>> &dp){
        if(n < 0 && m < 0)return 1;
        if(m < 0)return 0;
        if(n < 0){
            if(p[m] == '*')return helper(n, m - 2, s, p, dp);
            return 0;
        }
        if(dp[n][m] != -1)return dp[n][m];
        if(s[n] == p[m] || p[m] == '.'){
            dp[n][m] = helper(n - 1, m - 1, s, p, dp);
        }
        else if(p[m] == '*'){
            dp[n][m] = 0;
            if(p[m - 1] == s[n] || p[m - 1] == '.'){
                dp[n][m] = helper(n - 1, m - 2, s, p, dp) || helper(n - 1, m, s, p, dp);
            }
            dp[n][m] |= helper(n, m - 2, s, p, dp);
        }
        else{
            dp[n][m] = 0;
        }
        return dp[n][m];
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, p, dp) == 1;
    }
};