class Solution {
    // int helper(int n, vector<int> &dp){
    //     if(n < 1)return false;
    //     if(dp[n] != -1)return dp[n];
    //     dp[n] = 0;
    //     for(int i = 1; i * i <= n; i++){
    //         if(helper(n - i * i, dp) == 0){
    //             dp[n] = 1;
    //         }
    //     }
    //     return dp[n];
    // }
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                if(!dp[i - j * j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};