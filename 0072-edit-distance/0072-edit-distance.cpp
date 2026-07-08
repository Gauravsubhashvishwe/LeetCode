class Solution {
    int helper(int n, int m, string &a, string &b, vector<vector<int>> &dp){
        if(n < 0)return m + 1;
        if(m < 0)return n + 1;
        if(dp[n][m] != -1)return dp[n][m];
        if(a[n] == b[m]){
            dp[n][m] = helper(n - 1, m - 1, a, b, dp);
        }
        else{
            dp[n][m] = 1 + min(helper(n - 1, m, a, b, dp), min(helper(n, m - 1, a, b, dp), helper(n - 1, m - 1, a, b, dp)));
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, word1, word2, dp);
    }
};