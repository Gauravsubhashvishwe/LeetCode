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
    TreeNode* helper(int srt, int lst, vector<int>& nums){
        if(srt > lst)return nullptr;
        int mid = srt + (lst - srt) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(srt, mid - 1, nums);
        node->right = helper(mid + 1, lst, nums);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n - 1, nums);
    }
};