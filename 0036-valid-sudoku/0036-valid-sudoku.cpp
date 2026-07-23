class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<int, int>> row(9), col(9), box(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')continue;
                if(row[i].find(board[i][j] - '0') == row[i].end()){
                    row[i][board[i][j] - '0'] = 1;
                }
                else return false;

                if(col[j].find(board[i][j] - '0') == col[j].end()){
                    col[j][board[i][j] - '0'] = 1;
                }
                else return false;

                if(box[(i/3) * 3 + j/3].find(board[i][j] - '0') == box[(i/3) * 3 + j/3].end()){
                    box[(i/3) * 3 + j/3][board[i][j] - '0'] = 1;
                }
                else return false;
            }
        }
        return true;
    }
};