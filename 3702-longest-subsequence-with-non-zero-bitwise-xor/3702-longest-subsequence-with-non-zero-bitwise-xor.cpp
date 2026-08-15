class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cnt = 0;
        int x_or = 0;
        for(int num : nums){
            x_or = x_or ^ num;
            if(num == 0)cnt++;
        }
        if(x_or != 0)return nums.size();
        if(cnt < nums.size())return nums.size() - 1;
        return 0;
    }
};