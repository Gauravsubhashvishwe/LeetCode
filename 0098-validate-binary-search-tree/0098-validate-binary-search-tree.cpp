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
public:
    bool is_valid_bst(TreeNode* root, long long maxl, long long minl){
        if(root == NULL)return true;
        if(root->val >= maxl || root->val <= minl)return false;
        return (is_valid_bst(root->left, root->val, minl) && is_valid_bst(root->right, maxl, root->val));
    }

    bool isValidBST(TreeNode* root) {
        return is_valid_bst(root, LONG_LONG_MAX, LONG_LONG_MIN);
    }
};