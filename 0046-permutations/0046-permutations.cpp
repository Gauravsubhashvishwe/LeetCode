class Solution {
    void helper(vector<int> &curr, vector<bool> &visit, vector<vector<int>> &result, vector<int> &nums){
        if(curr.size() == visit.size()){
            result.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visit[i]){
                visit[i] = true;
                curr.push_back(nums[i]);
                helper(curr, visit, result, nums);
                curr.pop_back();
                visit[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n, false);
        vector<vector<int>> result;
        vector<int> curr;
        helper(curr, visit, result, nums);
        return result;
    }
};