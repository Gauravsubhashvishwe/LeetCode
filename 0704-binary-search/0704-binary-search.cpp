class Solution {
    int helper(int srt, int lst, int key, vector<int> &nums){
        if(srt > lst)return -1;
        int mid = srt + (lst - srt) / 2;
        if(nums[mid] == key)return mid;
        else if(nums[mid] > key){
            return helper(srt, mid - 1, key, nums);
        }
        else return helper(mid + 1, lst, key, nums);
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, n - 1, target, nums);
    }
};