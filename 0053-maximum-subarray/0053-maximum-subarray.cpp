class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int max_s = nums[0];
        for(int i = 1; i < n; i++){
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            max_s = max(sum , max_s);
        }
        return max_s;
    }
};