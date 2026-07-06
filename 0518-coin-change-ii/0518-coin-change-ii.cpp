class Solution {
    int helper(int n, int target, vector<int>& coins, vector<vector<int>> &dp){
        if(target == 0)return 1;
        if(n < 0 || target < 0)return 0;
        if(dp[n][target] != -1)return dp[n][target];
        if(coins[n] > target){
            dp[n][target] = helper(n - 1, target, coins, dp);
        }
        else{
            dp[n][target] = (helper(n, target - coins[n], coins, dp) + helper(n - 1, target, coins, dp));
        }
        return dp[n][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1 ,amount, coins, dp);
    }
};