class Solution {
    struct Node{
        char leftchar;
        char rightchar;
        int length;
        int prefix;
        int suffix;
        int best;
    };
    vector<Node> tree;
    string s;

    Node merge(const Node& left, const Node &right){
        Node res;

        res.leftchar = left.leftchar;
        res.rightchar  = right.rightchar;
        res.length = left.length + right.length;

        res.prefix = left.prefix;
        if(left.prefix == left.length && left.rightchar == right.leftchar){
            res.prefix += right.prefix;
        }

        res.suffix = right.suffix;
        if(right.suffix == right.length && right.leftchar == left.rightchar){
            res.suffix += left.suffix;
        }

        res.best = max(left.best, right.best);
        if(left.rightchar == right.leftchar){
            res.best = max(res.best, left.suffix + right.prefix);
        }

        return res;
    }

    void build(int node, int start, int end){
        if(start == end){
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, char c){
        if(start == end){
            tree[node] = {c, c, 1, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if(idx <= mid){
            update(2 * node + 1, start, mid, idx, c);
        }
        else{
            update(2 * node + 2, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        this->s = s;

        tree.resize(4 * n);
        build(0, 0, n - 1);

        int k = queryCharacters.length();
        vector<int> ans;
        ans.reserve(k);

        for(int i = 0; i < k; i++){
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[0].best);
        }

        return ans;
    }
};