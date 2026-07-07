class Solution {
    int helper(int n, int m, string &a, string &b, vector<vector<int>> &dp){
        if(n < 0 || m < 0)return 0;
        if(dp[n][m] != -1)return dp[n][m];
        if(a[n] == b[m]){
            dp[n][m] = 1 + helper(n - 1, m - 1, a, b, dp);
        }
        else{
            dp[n][m] = max(helper(n - 1, m, a, b, dp), helper(n, m - 1, a, b, dp));
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = helper(n - 1, m - 1, word1, word2, dp);

        return (n + m - 2 * res);
    }
};