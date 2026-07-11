class Solution {
    int helper_l(int srt, int lst, int target, vector<int> &nums){
        if(srt > lst)return srt;

        int mid = srt + (lst - srt) / 2;
        if(nums[mid] >= target){
            return helper_l(srt, mid - 1, target, nums);
        }
        else{
            return helper_l(mid + 1, lst, target, nums);
        }
    }

    int helper_u(int srt, int lst, int target, vector<int> &nums){
        if(srt > lst)return srt;

        int mid = srt + (lst - srt) / 2;
        if(nums[mid] > target){
            return helper_u(srt, mid - 1, target, nums);
        }
        else{
            return helper_u(mid + 1, lst, target, nums);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)return {-1, -1};

        int lo_b, up_b;
        
        lo_b = helper_l(0, n - 1, target, nums);
        if(lo_b == n || nums[lo_b] != target)return {-1, -1};

        up_b = helper_u(0, n - 1, target, nums);
        up_b--;

        return {lo_b, up_b};
    }
};