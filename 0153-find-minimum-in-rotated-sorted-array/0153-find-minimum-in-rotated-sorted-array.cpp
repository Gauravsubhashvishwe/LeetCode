class Solution {
    int helper(int srt, int lst, vector<int> &nums){
        if(srt == lst)return nums[srt];
        if(nums[srt] < nums[lst])return nums[srt];
        
        int mid = srt + (lst - srt) / 2;

        if(nums[srt] <= nums[mid]){
            return helper(mid + 1, lst, nums);
        }
        else{
            return helper(srt, mid, nums);
        }
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n - 1, nums);
    }
};