class Solution {
    int helper(int n, vector<int> &nums, vector<int> &dp){
        if(n < 0)return 0;
        if(n == 0)return nums[0];
        if(n == 1)return max(nums[0], nums[1]);
        if(dp[n] != -1)return dp[n];
        dp[n] = max(helper(n - 2, nums, dp), helper(n - 3, nums, dp)) + nums[n];
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(helper(n - 2, nums, dp), helper(n - 1, nums, dp));
    }
};