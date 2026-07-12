class Solution {
    int helper(int srt, int lst, vector<int> &nums){
        if(srt > lst)return -1;
        if(srt == lst)return nums[srt];
        int mid = srt + (lst - 1);
        if(mid % 2 == 0){
            if(nums[mid] == nums[mid + 1]){
                return helper(mid + 2, lst, nums);
            }
            else return helper(srt, mid, nums);
        }
        else{
            if(nums[mid] == nums[mid - 1]){
                return helper(mid + 1, lst, nums);
            }
            else{
                return helper(srt, mid, nums);
            }
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return -1;
        else if(n == 1)return nums[0];
        return helper(0, n - 1, nums);
    }
};