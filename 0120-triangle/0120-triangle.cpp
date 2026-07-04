class Solution {
    const int inf = 1e9 + 7;
    int m;
    int helper(int i, int j, vector<vector<int>> &tri, vector<vector<int>> &dp){
        if(i >= m)return 0;
        if(j > i)return inf;
        if(dp[i][j] != inf)return dp[i][j];
        dp[i][j] = min(helper(i + 1, j, tri, dp), helper(i + 1, j + 1, tri, dp)) + tri[i][j];
        return dp[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        if(m == 0)return 0;
        vector<vector<int>> dp(m, vector<int>(m, inf));
        return helper(0, 0, triangle, dp);
    }
};