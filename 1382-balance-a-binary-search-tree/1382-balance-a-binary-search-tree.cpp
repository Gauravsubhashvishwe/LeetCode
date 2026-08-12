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
    void helper(TreeNode* dummy, int cnt){
        TreeNode* scn = dummy;
        for(int i = 0; i < cnt; i++){
            TreeNode* curr = scn->right;
            TreeNode* r_child = curr->right;

            curr->right = r_child->left;
            r_child->left = curr;
            scn->right = r_child;

            scn = r_child;
        }
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)return root;

        TreeNode dummy(0);
        dummy.right = root;

        TreeNode* it = &dummy;
        int cnt = 0;
        while(it->right != nullptr){
            if(it->right->left != nullptr){
                TreeNode* curr = it->right;
                TreeNode* l_child = curr->left;

                curr->left = l_child->right;
                l_child->right = curr;
                it->right = l_child;
            }
            else{
                it = it->right;
                cnt++;
            }
        }

        int m = 1;
        while(m <= cnt + 1){
            m *= 2;
        }
        m = m / 2 - 1;
        helper(&dummy, cnt - m);
        while(m > 1){
            m /= 2;
            helper(&dummy, m);
        }
        return dummy.right;
    }
};