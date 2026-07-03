class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int m = grid.size();
        if(m == 0)return 0;
        int n = grid[0].size();
        queue<pair<int, int>> trav;

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                grid[i][0] = 2;
                trav.push({i, 0});
            }
            if(grid[i][n - 1] == 1){
                grid[i][n - 1] = 2;
                trav.push({i, n - 1});
            }
        }

        for(int j = 1; j < n - 1; j++){
            if(grid[0][j] == 1){
                grid[0][j] = 2;
                trav.push({0, j});
            }
            if(grid[m - 1][j] == 1){
                grid[m - 1][j] = 2;
                trav.push({m - 1, j});
            }
        }

        vector<int> it = {-1, 0, 0, 1};
        vector<int> jt = {0, -1, 1, 0};

        while(!trav.empty()){
            auto [i, j] = trav.front();
            trav.pop();

            for(int x = 0; x < 4; x++){
                if((i + it[x] >= 0 && i + it[x] < m) && (j + jt[x] >= 0 && j + jt[x] < n)){
                    if(grid[i + it[x]][j + jt[x]] == 1){
                        grid[i + it[x]][j + jt[x]] = 2;
                        trav.push({i + it[x], j + jt[x]});
                    }
                }
            }
        }
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    result++;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 1;
                }
            }
        }
        return result;
    }
};