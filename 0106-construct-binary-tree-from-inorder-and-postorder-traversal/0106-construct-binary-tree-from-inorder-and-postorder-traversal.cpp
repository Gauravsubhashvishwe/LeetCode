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
    int idx;
    TreeNode* build_tree(vector<int> &inorder, vector<int> &postorder, int srt, int lst){
        if(srt > lst)return NULL;
        int n = inorder.size();
        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;
        if(srt == lst)return root;
        int id = 0;
        for(int i = srt; i <= lst; i++){
            if(inorder[i] == root->val){
                id = i;
                break;
            }
        }
        root->right = build_tree(inorder, postorder, id + 1, lst);
        root->left = build_tree(inorder, postorder, srt, id - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = inorder.size() - 1;
        return build_tree(inorder, postorder, 0, inorder.size() - 1);
    }
};