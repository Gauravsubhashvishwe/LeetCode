class Solution {
    void helper(int i, int n, int k, vector<int> &curr, vector<vector<int>> &result){
        if(k == curr.size()){
            result.push_back(curr);
            return;
        }
        if(i > n || curr.size() + (n - i + 1) < k)return;
        for(int j = i; j <= n; j++){
            curr.push_back(j);
            helper(j + 1, n, k, curr, result);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(1, n, k, curr, result);
        return result;
    }
};