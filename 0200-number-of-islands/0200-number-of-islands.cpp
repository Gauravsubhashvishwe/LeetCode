class Solution {
    vector<int> it = {-1, 0, 0, 1};
    vector<int> jt = {0, -1, 1, 0};
    int n,m;

    void helper(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visit){

        visit[i][j] = true;
        for(int k = 0; k < 4; k++){
            if((i + it[k] >= 0 && i + it[k] < n) && (j + jt[k] >= 0 && j + jt[k] < m)){
                if(grid[i + it[k]][j + jt[k]] == '1' && !visit[i + it[k]][j + jt[k]]){
                    helper(i + it[k], j + jt[k], grid, visit);
                }
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0)return 0;
        m = grid[0].size();

        int result = 0;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    helper(i, j, grid, visit);
                    result++;
                }
            }
        }
        return result;
    }
};