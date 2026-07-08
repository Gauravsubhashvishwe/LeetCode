class Solution {
    int helper(int n, int m, string &s, string &t, vector<vector<int>> &dp){
        if(n < 0 || m < 0)return 0;
        if(dp[n][m] == -1){
            if(s[n] == t[m]){
                if(m == 0){
                    dp[n][m] = helper(n - 1, m, s, t, dp) + 1;
                }
                else{
                    dp[n][m] = helper(n - 1, m, s, t, dp) + helper(n - 1, m - 1, s, t, dp); 
                }
            }
            else{
                dp[n][m] = helper(n - 1, m, s, t, dp);
            }
        }
        return dp[n][m];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, t, dp);
    }
};