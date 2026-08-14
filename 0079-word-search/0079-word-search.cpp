class Solution {
    int n, m;
    vector<int> di = {0, -1, 0, 1};
    vector<int> dj = {-1, 0, 1, 0};
    void helper(int i, int j, int k, string &word, vector<vector<char>> &board, vector<vector<bool>> &visit, bool &found){
        if(k == word.size()){
            found = true;
            return;
        }
        for(int l = 0; l < 4; l++){
            if(i + di[l] >= 0 && i + di[l] < n && j + dj[l] >= 0 && j + dj[l] < m){
                if(board[i + di[l]][j + dj[l]] == word[k] && !visit[i + di[l]][j + dj[l]]){
                    visit[i + di[l]][j + dj[l]] = true;
                    helper(i + di[l], j + dj[l], k + 1, word, board, visit, found);
                    if(found)return;
                    visit[i + di[l]][j + dj[l]] = false;
                }
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        if(n == 0)return false;
        m = board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    visit[i][j] = true;
                    helper(i, j, 1, word, board, visit, found);
                    visit[i][j] = false;
                }
            }
        }
        return found;
    }
};