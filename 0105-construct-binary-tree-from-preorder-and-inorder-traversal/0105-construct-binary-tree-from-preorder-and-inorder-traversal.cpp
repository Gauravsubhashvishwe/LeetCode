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
    TreeNode* build_tree(vector<int> &preor, vector<int> &inor, int srt, int lst, int &idx){
        if(srt > lst)return NULL;
        TreeNode* node = new TreeNode(preor[idx]);
        idx++;
        if(srt == lst)return node;

        int i = srt;
        for(i = srt; i <= lst; i++){
            if(inor[i] == node->val)break;
        }
        node->left = build_tree(preor, inor, srt, i - 1, idx);
        node->right = build_tree(preor, inor, i + 1, lst, idx);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build_tree(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};