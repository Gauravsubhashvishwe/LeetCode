/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> result;
    bool visit;
    int helper(TreeNode* root, TreeNode* target, int k){
        if(root == NULL)return -1;
        if(visit || root == target){
            visit = true;
            if(k == 0){
                result.push_back(root->val);
            }
            else{
                helper(root->left, target, k - 1);
                helper(root->right, target, k - 1);
            }
            return 0;
        }

        int left = helper(root->left, target, k);
        
        if(left != -1){
            if(k == left + 1){
                result.push_back(root->val);
            }
            else{
                helper(root->right, target, k - left - 2);
            }
            return left + 1;
        }

        int right = helper(root->right, target, k);

        if(right != -1){
            if(k == right + 1){
                result.push_back(root->val);
            }
            else{
                helper(root->left, target, k - right - 2);
            }
            return right + 1;
        }
        return -1;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        visit = false;
        helper(root, target, k);
        return result;
    }
};