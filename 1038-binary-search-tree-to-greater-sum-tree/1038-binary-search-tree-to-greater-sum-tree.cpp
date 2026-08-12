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
    int add_f = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr)return root;
        bstToGst(root->right);
        add_f += root->val;
        root->val = add_f;
        bstToGst(root->left);
        return root;
    }
};