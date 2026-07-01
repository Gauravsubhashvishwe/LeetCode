class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int creach = 0;
        for(int i = 0; i < n && i <= creach; i++){
            creach = max(creach, i + nums[i]);
            if(creach >= n - 1)return true;
        }
        if(creach >= n - 1)return true;
        return false;
    }
};