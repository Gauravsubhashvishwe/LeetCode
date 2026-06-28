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
    class hpr{
    public:
        int mx;
        int mn;
        int sm;
        int result;
        hpr(){
            mx = INT_MIN;
            mn = INT_MAX;
            sm = 0;
            result = 0;
        }
    };

    hpr* helper(TreeNode* root){
        if(root == NULL)return new hpr();
        hpr* left = helper(root->left);
        hpr* right = helper(root->right);
        hpr* result = new hpr();
        
        if(root->val > left->mx && root->val < right->mn){
            result->sm = left->sm + right->sm + root->val;
            result->mn = (left->mn == INT_MAX)? root->val: left->mn;
            result->mx = (right->mx == INT_MIN)? root->val: right->mx;
        }
        else{
            result->mn = INT_MIN;
            result->mx = INT_MAX;
        }
        result->result = max({left->result, right->result, result->sm});

        return result;
    }
public:
    int maxSumBST(TreeNode* root) {
        return helper(root)->result;
    }
};