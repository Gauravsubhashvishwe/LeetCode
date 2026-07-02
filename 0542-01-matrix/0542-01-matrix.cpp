class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int inf = 1e9 + 7;
        int m = mat.size();
        if(m == 0)return {{}};
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, inf));
        queue<pair<int, int>> trav;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    trav.push({i, j});
                }
            }
        }

        vector<int> it = {-1, 0, 0, 1};
        vector<int> jt = {0, -1, 1, 0};

        while(!trav.empty()){
            auto [i, j] = trav.front();
            trav.pop();

            for(int x = 0; x < 4; x++){
                if((i + it[x] >= 0 && i + it[x] < m) && (j + jt[x] >= 0 && j + jt[x] < n)){
                    if(result[i + it[x]][j + jt[x]] > result[i][j] + 1){
                        result[i + it[x]][j + jt[x]] = result[i][j] + 1;
                        trav.push({i + it[x], j + jt[x]});
                    }
                }
            }
        }
        return result;
    }
};