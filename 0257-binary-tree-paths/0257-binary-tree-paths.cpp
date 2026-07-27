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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)return {};
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for(auto &path : left){
            path = to_string(root->val) + "->" + path;
        }
        for(auto &path : right){
            path = to_string(root->val) + "->" + path;
        }
        left.insert(left.end(), right.begin(), right.end());
        if(left.size() == 0){
            left.push_back(to_string(root->val));
        }
        return left;
    }
};