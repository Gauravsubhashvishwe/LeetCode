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
class BSTIterator {
    stack<TreeNode*> inor;
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }

    void helper(TreeNode* root) {
        if(root == NULL)return;
        TreeNode* it = root;
        while(it != NULL){
            inor.push(it);
            it = it->left;
        }
        return;
    }
    
    int next() {
        if(inor.empty())return -1;
        TreeNode* nxt = inor.top();
        inor.pop();
        helper(nxt->right);
        return nxt->val;
    }
    
    bool hasNext() {
        return !inor.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */