class Solution {
    int helper(int srt, int lst, int target, vector<int> &nums){
        if(srt > lst)return srt;

        int mid = srt + (lst - srt) / 2;
        if(nums[mid] >= target){
            return helper(srt, mid - 1, target, nums);
        }
        else{
            return helper(mid + 1, lst, target, nums);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, n - 1, target, nums);
    }
};