class Solution {
    const int inf = 1e9 + 7;
    int helper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(m < 0 || n < 0)return inf;
        if(m == 0 && n == 0)return grid[0][0];
        if(dp[m][n] != -1)return dp[m][n];
        dp[m][n] = min(helper(m - 1, n, grid, dp), helper(m, n - 1, grid, dp)) + grid[m][n];
        return dp[m][n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, grid, dp);
    }
};