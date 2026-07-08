class Solution {
    enum bits:int8_t {N, T, F};
    bits helper(int n, int m, string &a, string &b, vector<vector<bits>> &dp){
        if(n < 0 && m < 0)return T;
        if(m < 0)return F;
        if(n < 0){
            for(int i = 0; i <= m; i++){
                if(b[i] != '*')return F;
            }
            return T;
        }
        if(dp[n][m] != N)return dp[n][m];
        if(b[m] == '*'){
            dp[n][m] = ((helper(n - 1, m, a, b, dp) == T) || (helper(n - 1, m - 1, a, b, dp) == T) || (helper(n, m - 1, a, b, dp) == T))? T : F;
        }
        else if(b[m] == '?'){
            dp[n][m] = helper(n - 1, m - 1, a, b, dp);
        }
        else if (a[n] == b[m]){
            dp[n][m] = helper(n - 1, m - 1, a, b, dp);
        }
        else{
            dp[n][m] = F;
        }
        return dp[n][m];
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bits>> dp(n, vector<bits>(m, N));
        return (helper(n - 1, m - 1, s, p, dp) == T)? true: false;
    }
};