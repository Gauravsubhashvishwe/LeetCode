class Solution {
    int helper(int srt, int lst, vector<int> &nums){
        if(srt == lst)return srt;
        int mid = srt + (lst - srt) / 2;

        if(nums[mid] < nums[mid + 1]){
            return helper(mid + 1, lst, nums);
        }
        else{
            return helper(srt, mid, nums);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n - 1, nums);
    }
};