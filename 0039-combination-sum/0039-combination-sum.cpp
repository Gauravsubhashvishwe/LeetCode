class Solution {
    void helper(int i, int n,vector<int> &curr, int target, vector<int>& candidates, vector<vector<int>> &result){
        if(i >= n || target < 0)return;
        if(target == 0){
            result.push_back(curr);
            return;
        }
        helper(i + 1, n, curr, target, candidates, result);
        curr.push_back(candidates[i]);
        helper(i, n, curr, target - candidates[i], candidates, result);
        curr.pop_back();
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> curr;
        helper(0, n, curr, target, candidates, result);
        return result;
    }
};