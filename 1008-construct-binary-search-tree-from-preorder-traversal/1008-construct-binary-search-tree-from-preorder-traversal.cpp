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
    TreeNode* build_bst(vector<int> &preorder, int &idx, int max, int min){
        if(idx >= preorder.size())return NULL;
        if(preorder[idx] > max || preorder[idx] < min)return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build_bst(preorder, idx, root->val, min);
        root->right = build_bst(preorder, idx, max, root->val);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build_bst(preorder, idx, INT_MAX, INT_MIN);
    }
};