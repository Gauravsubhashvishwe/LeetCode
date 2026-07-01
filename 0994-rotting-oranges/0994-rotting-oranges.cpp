class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> it = {-1, 0, 0, 1};
        vector<int> jt = {0, -1, 1, 0};
        int m = grid.size();
        if(m == 0)return 0;
        int n = grid[0].size();

        int rot_cnt = 0;

        queue<pair<int, int>> trav;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    trav.push({i, j});
                }
                else if(grid[i][j] == 1){
                    rot_cnt++;
                }
            }
        }

        if(rot_cnt == 0)return 0;

        int time_r = 0;
        while(!trav.empty()){
            int l = trav.size();
            bool rot_tt = false;
            for(int k = 0; k < l; k++){
                auto [i, j] = trav.front();
                trav.pop();
                for(int x = 0; x < 4; x++){
                    if(((i + it[x]) < m) && ((i + it[x]) >= 0) && ((j + jt[x]) < n) && ((j + jt[x]) >= 0) && (grid[i + it[x]][j + jt[x]] == 1)){
                        grid[i + it[x]][j + jt[x]] = 2;
                        trav.push({i + it[x], j + jt[x]});
                        rot_cnt--;
                        rot_tt = true;
                    }
                }
            }
            if(rot_tt)time_r++;
        }
        if(rot_cnt == 0)return time_r;
        return -1;
    }
};