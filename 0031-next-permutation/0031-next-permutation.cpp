class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)return;

        int bk_p = -1;
        int sw_l = -1;

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                bk_p = i;
                break;
            }
        }

        if(bk_p == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > bk_p; i--){
            if(nums[i] > nums[bk_p]){
                sw_l = i;
                break;
            }
        }

        swap(nums[sw_l], nums[bk_p]);
        reverse(nums.begin() + bk_p + 1, nums.end());
        return;
    }
};