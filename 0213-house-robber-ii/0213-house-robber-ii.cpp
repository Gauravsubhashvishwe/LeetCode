class Solution {
    int helper(int s, int n, vector<int> &nums, vector<vector<int>> &dp){
        if(n < 0)return 0;
        if(s == 0){
            if(n == 0)return nums[0];
            if(n == 1)return max(nums[0], nums[1]);
        }
        if(s == 1){
            if(n == 0)return 0;
            if(n == 1)return nums[1];
        }
        if(dp[s][n] != -1)return dp[s][n];
        dp[s][n] = max(helper(s, n - 2, nums, dp) + nums[n], helper(s, n - 1, nums, dp));
        return dp[s][n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<vector<int>> dp(2, vector<int>(n, -1));
        return max(helper(0, n - 2, nums, dp), helper(1 , n - 1, nums, dp));
    }
};