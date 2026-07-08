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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)return {};
        vector<int> result;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            int n = level.size();
            for(int i = 0; i < n; i++){
                TreeNode* front = level.front();
                level.pop();
                if(front->left != nullptr){
                    level.push(front->left);
                }
                if(front->right != nullptr){
                    level.push(front->right);
                }
                if(i == n - 1){
                    result.push_back(front->val);
                }
            }
        }
        return result;
    }
};