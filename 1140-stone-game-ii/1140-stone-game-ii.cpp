class Solution {
    int helper(int i, int m, vector<int>& piles, vector<vector<int>> &dp, vector<int> &suf_sum){
        int n = piles.size();
        if(i == n)return 0;
        if(i + 2 * m >= n)return suf_sum[i];
        if(dp[i][m] != 0)return dp[i][m];
        int min_os = INT_MAX;
        for(int x = 1; x <= 2*m; x++){
            min_os = min(min_os, helper(i + x, max(m,x), piles, dp, suf_sum));
        }
        dp[i][m] = suf_sum[i] - min_os;
        return dp[i][m];
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        vector<int> suf_sum(n,0);
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                suf_sum[i] = piles[i];
                continue;
            }
            suf_sum[i] = suf_sum[i + 1] + piles[i];
        }

        return helper(0, 1, piles, dp, suf_sum);
    }
};