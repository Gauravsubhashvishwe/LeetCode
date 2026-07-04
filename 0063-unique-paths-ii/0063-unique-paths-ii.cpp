class Solution {
    int helper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(m < 0 || n < 0)return 0;
        if(dp[m][n] != -1)return dp[m][n];
        if(grid[m][n] == 1){
            dp[m][n] = 0;
            return 0;
        }
        if(m == 0 && n == 0)return 1;
        dp[m][n] = helper(m - 1, n, grid, dp) + helper(m, n - 1, grid, dp);
        return dp[m][n];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
};