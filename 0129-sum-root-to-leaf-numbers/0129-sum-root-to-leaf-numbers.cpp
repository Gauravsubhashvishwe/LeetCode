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
    int helper(TreeNode* root, int val){
        if(root == nullptr)return 0;
        val = val * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr)return val;

        return helper(root->left, val) + helper(root->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};