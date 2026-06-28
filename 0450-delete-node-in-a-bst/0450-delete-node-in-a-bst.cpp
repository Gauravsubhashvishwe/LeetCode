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
    void pnxt(TreeNode* root, TreeNode* &nxt){
        if(root == NULL)return;
        pnxt(root->left, nxt);
        if(nxt != NULL)return;
        nxt = root;
        return;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                TreeNode* toret = root->right;
                delete root;
                return toret;
            }
            else if(root->right == NULL){
                TreeNode* toret = root->left;
                delete root;
                return toret;
            }
            TreeNode* nxt = NULL;
            pnxt(root->right, nxt);
            swap(root->val, nxt->val);
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right =deleteNode(root->right, key);
        }
        return root;
    }
};