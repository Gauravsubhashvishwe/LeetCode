class Solution {
    void helper(int i, int n,vector<int> &curr, int target, vector<int>& candidates, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(curr);
            return;
        }
        if(i >= n || target < 0)return;
        for(int j = i; j < n; j++){
            if(j > i && candidates[j] == candidates[j - 1]){
                continue;
            }

            if(candidates[j] > target){
                break;
            }

            curr.push_back(candidates[j]);
            helper(j + 1, n, curr, target - candidates[j], candidates, result);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> curr;
        helper(0, n, curr, target, candidates, result);
        return result;
    }
};