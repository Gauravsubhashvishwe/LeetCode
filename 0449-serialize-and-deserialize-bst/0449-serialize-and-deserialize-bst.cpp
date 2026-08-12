/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void helper_s(TreeNode* root, string &s){
        if(root == nullptr)return;

        s += to_string(root->val) + " ";
        helper_s(root->left, s);
        helper_s(root->right, s);
    }

    TreeNode* helper_d(stringstream &ss, string &item, int minval, int maxval){
        if(item.empty())return nullptr;

        int val = stoi(item);
        if(val < minval || val > maxval)return nullptr;
        TreeNode* root = new TreeNode(val);

        if(!(ss >> item)){
            item = "";
        }

        root->left = helper_d(ss, item, minval, val);
        root->right = helper_d(ss, item, val, maxval);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        helper_s(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        queue<int> q;

        ss >> item;

        return helper_d(ss, item, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;