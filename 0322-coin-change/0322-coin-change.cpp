class Solution {
    int helper(vector<int> &coins, int amt, vector<int> &dp){
        if(amt < 0)return -1;
        if(amt == 0)return 0;

        if(dp[amt] != -2){
            return dp[amt];
        }
        int min_c = INT_MAX;
        for(auto coin : coins){
            int res = helper(coins, amt - coin, dp);

            if(res >= 0 && res < min_c){
                min_c = res + 1;
            }
        }
        dp[amt] = (min_c == INT_MAX)? -1 : min_c;
        return dp[amt]; 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        int result = helper(coins, amount, dp);
        return (result == -2)? -1 : result;
    }
};