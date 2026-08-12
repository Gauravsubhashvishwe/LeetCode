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
    stack<TreeNode*> trav_f,trav_s;
    void helper(TreeNode* root1, bool n){
        TreeNode* it_o(root1);
        while(it_o != nullptr){
            if(n)trav_f.push(it_o);
            else trav_s.push(it_o);
            it_o = it_o->left;
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        TreeNode *it_o(nullptr), *it_s(nullptr);
        
        trav_f.push(nullptr);
        trav_s.push(nullptr);

        helper(root1, true);
        helper(root2, false);
        
        it_o = trav_f.top();
        trav_f.pop();
        it_s = trav_s.top();
        trav_s.pop();
        
        while(it_o != nullptr && it_s != nullptr){
            if(it_o->val < it_s->val){
                result.push_back(it_o->val);
                helper(it_o->right, true);
                it_o = trav_f.top();
                trav_f.pop();
            }
            else{
                result.push_back(it_s->val);
                helper(it_s->right, false);
                it_s = trav_s.top();
                trav_s.pop();
            }
        }

        while(it_o != nullptr){
            helper(it_o->right, true);
            result.push_back(it_o->val);
            it_o = trav_f.top();
            trav_f.pop();
        }
        
        while(it_s != nullptr){
            result.push_back(it_s->val);
            helper(it_s->right, false);
            it_s = trav_s.top();
            trav_s.pop();
        }

        return result;
    }
};