/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    long long sum = 0;
    vector<long long> presum = {0};
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == 0)return 0;
        int result = 0;
        sum += root->val;
        for(int i = presum.size() - 1; i >= 0; i--){
            if(sum - presum[i] == targetSum)result++;
        }
        presum.push_back(sum);
        result += pathSum(root->left, targetSum);
        result += pathSum(root->right, targetSum);
        sum -= root->val;
        presum.pop_back();
        return result;
    }
};