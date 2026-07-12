class Solution {
    bool helper(int srt, int lst, const int &target, const vector<int> &nums){
        if(srt > lst)return false;

        int mid = srt + (lst - srt) / 2;

        if(nums[mid] == target)return true;

        else if(nums[srt] == nums[mid] && nums[mid] == nums[lst]){
            return helper(srt + 1, lst - 1, target, nums);
        }

        else if(target < nums[mid]){
            if((target >= nums[srt] && nums[srt] <= nums[mid]) || (nums[srt] > nums[mid])){
                return helper(srt, mid - 1, target, nums);
            }
            else{
                return helper(mid + 1, lst, target, nums);
            }
        }

        else{
            if((target <= nums[lst] && nums[mid] <= nums[lst]) || (nums[mid] > nums[lst])){
                return helper(mid + 1, lst, target, nums);
            }
            else{
                return helper(srt, mid - 1, target, nums);
            }
        }
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, n - 1, target, nums);
    }
};