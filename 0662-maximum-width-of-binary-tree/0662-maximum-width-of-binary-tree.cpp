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
    int widthOfBinaryTree(TreeNode* root){
        if(root == NULL)return 0;
        int result = INT_MIN;
        queue<pair<TreeNode*, long long>> trav;
        trav.push({root, 0});

        while(!trav.empty()){
            int n = trav.size();
            pair<TreeNode*, long long> front = trav.front();
            long long f_vodr = front.second;
            long long lst = trav.back().second;

            result = max(result, (int)(lst - f_vodr + 1));
            for(int i = 0; i < n; i++){
                front = trav.front();
                trav.pop();
                int idx = front.second;

                if(front.first->left != NULL){
                    trav.push({front.first->left, (long long)2 * idx + 1});
                }
                if(front.first->right != NULL){
                    trav.push({front.first->right, (long long)2* idx + 2});
                }
            }
        }
        return result;
    }
};