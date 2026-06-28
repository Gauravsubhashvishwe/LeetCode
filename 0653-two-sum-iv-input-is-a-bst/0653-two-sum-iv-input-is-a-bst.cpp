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
    unordered_map<int, bool> visit;
    void helper(TreeNode* root){
        if(root == NULL)return;
        helper(root->left);
        visit[root->val] = true;
        helper(root->right);
        return;
    }

    bool two_sum(TreeNode* root, int k){
        if(root == NULL)return false;
        visit[root->val] = false;
        if(visit.find(k - root->val) != visit.end() && visit[k - root->val])return true;
        visit[root->val] = true;
        return (two_sum(root->left, k) || two_sum(root->right, k));
    }

public:
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        return two_sum(root, k);
    }
};