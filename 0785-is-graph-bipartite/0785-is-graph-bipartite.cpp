class Solution {
    int n;
    bool helper(int i, vector<int> &grp, vector<vector<int>> &graph){
        int c_g = grp[i];
        for(auto p : graph[i]){
            if(grp[p] == -1){
                grp[p] = (c_g == 0)? 1: 0;
                if(!helper(p, grp, graph))return false;
            }
            else{
                if(grp[p] == c_g)return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> grp(n, -1);

        for(int i = 0; i < n; i++){
            if(grp[i] == -1){
                grp[i] = 1;
                if(!helper(i, grp, graph))return false;
            }
        }
        return true;
    }
};