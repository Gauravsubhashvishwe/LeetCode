class Solution {
    int helper(int srt, int lst, int target, vector<int> &nums){
        if(srt > lst)return -1;
        int mid = srt + (lst - srt) / 2;
        if(nums[mid] == target)return mid;

        else if(nums[mid] > target){
            if((target >= nums[srt] && nums[mid] >= nums[srt]) || nums[srt] > nums[mid]){
                return helper(srt, mid - 1, target, nums);
            }
            else{
                return helper(mid + 1, lst, target, nums);
            }
        }
        else{
            if((target <= nums[lst] && nums[mid] <= nums[lst]) || nums[mid] > nums[lst]){
                return helper(mid + 1, lst, target, nums);
            }
            else{
                return helper(srt, mid - 1, target, nums);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, n - 1, target, nums);
    }
};