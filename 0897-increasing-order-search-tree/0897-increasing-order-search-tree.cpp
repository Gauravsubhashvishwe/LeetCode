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
    TreeNode* n_root = nullptr;
    TreeNode* prev = nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)return n_root;
        increasingBST(root->left);
        root->left = nullptr;
        if(prev == nullptr){
            prev = root;
            n_root = root;
        }
        else{
            prev->right = root;
            prev = root;
        }
        increasingBST(root->right);
        return n_root;
    }
};