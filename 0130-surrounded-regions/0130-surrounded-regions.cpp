class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)return;
        int n = board[0].size();
        queue<pair<int, int>> trav;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'a';
                trav.push({i, 0});
            }
            if(board[i][n - 1] == 'O'){
                board[i][n - 1] = 'a';
                trav.push({i, n - 1});
            }
        }

        for(int j = 1; j < n - 1; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'a';
                trav.push({0, j});
            }
            if(board[m - 1][j] == 'O'){
                board[m - 1][j] = 'a';
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
                    if(board[i + it[x]][j + jt[x]] == 'O'){
                        board[i + it[x]][j + jt[x]] = 'a';
                        trav.push({i + it[x], j + jt[x]});
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'a'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};