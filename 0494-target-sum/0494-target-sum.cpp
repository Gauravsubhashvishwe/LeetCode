class Solution {
    int helper(int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target < 0)return 0;
        if(n < 0){
            return (target == 0)? 1 : 0;
        }

        if(dp[n][target] == -1){
            dp[n][target] = helper(n - 1, target, nums, dp) + helper(n - 1, target - nums[n], nums, dp);
        }
        return dp[n][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)return 0;
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum - target < 0 || (sum - target) % 2 != 0)return 0;
        sum -= target;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, nums, dp);
    }
};