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
    void find_fnodes(TreeNode* &prev, TreeNode* &curr, TreeNode* &first, TreeNode* &mid, TreeNode* &sec){
        if(curr == NULL)return;
        find_fnodes(prev, curr->left, first, mid, sec);
        if(prev != NULL && prev->val > curr->val){
            if(first == NULL){
                first = prev;
                mid = curr;
            }
            else{
                sec = curr;
            }
        }
        prev = curr;
        find_fnodes(prev, curr->right, first, mid, sec);
        return;
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        TreeNode* first = NULL;
        TreeNode* mid = NULL;
        TreeNode* sec = NULL;
        find_fnodes(prev, curr, first, mid, sec);
        if(sec == NULL && first != NULL && mid != NULL){
            swap(first->val, mid->val);
            return;
        }
        if(first != NULL && sec != NULL){
            swap(first->val, sec->val);
            return;
        }
        return;
    }
};