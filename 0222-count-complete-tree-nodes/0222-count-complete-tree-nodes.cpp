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
    int helper_l(TreeNode* root){
        int h = 0;
        while(root != NULL){
            root = root->left;
            h++;
        }
        return h;
    }
    int helper_r(TreeNode* root){
        int h = 0;
        while(root != NULL){
            root = root->right;
            h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)return 0;
        int l = helper_l(root);
        int r = helper_r(root);
        if(l == r)return (1 << l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};