class Solution {
    int helper(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j]){
            dp[i][j] = helper(i + 1, j - 1, s, dp);
        }
        else{
            dp[i][j] = min(helper(i + 1, j , s, dp), helper(i, j - 1, s, dp)) + 1;
        }
        return dp[i][j];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp);
    }
};