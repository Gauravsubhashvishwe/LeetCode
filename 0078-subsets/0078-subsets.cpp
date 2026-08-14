class Solution {
    void helper(int i, vector<int> &nums, vector<int> &curr, vector<vector<int>> &result){
        result.push_back(curr);
        for(int j = i; j < nums.size(); j++){
            curr.push_back(nums[j]);
            helper(j + 1, nums, curr, result);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> curr;
        helper(0, nums, curr, result);
        return result;
    }
};