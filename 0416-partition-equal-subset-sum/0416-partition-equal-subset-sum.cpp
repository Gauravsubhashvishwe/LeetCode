class Solution {
    bool helper(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0)return true;
        if(n < 0 || target < 0)return false;
        if(dp[n][target] != -1){
            return (dp[n][target] == 0)? false : true;
        }
        bool result = (helper(n - 1, target, arr, dp) || helper(n - 1, target - arr[n], arr, dp));
        dp[n][target] = (result)? 1 : 0;
        return result;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1)return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, nums, dp);
    }
};