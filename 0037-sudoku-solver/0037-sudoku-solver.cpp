class Solution {
    void helper(int i, int j, vector<vector<char>>& board, vector<unordered_map<int, bool>> &row, vector<unordered_map<int, bool>> &col, map<pair<int, int>, unordered_map<int, bool>> &box, bool &found){
        if(i == 9){
            found = true;
        }
        else if(j == 9){
            helper(i + 1, 0, board, row, col, box, found);
        }
        else if(board[i][j] != '.'){
            helper(i, j + 1, board, row, col, box, found);
        }
        else{
            for(int k = 1; k < 10; k++){
                if(!box[{i / 3, j / 3}][k] && !row[i][k] && !col[j][k]){
                    board[i][j] = ('0' + k);
                    box[{i / 3, j / 3}][k] = true;
                    row[i][k] = true;
                    col[j][k] = true;
                    helper(i, j + 1, board, row, col, box, found);
                    if(found)return;
                    board[i][j] = '.';
                    box[{i / 3, j / 3}][k] = false;
                    row[i][k] = false;
                    col[j][k] = false;
                }
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, bool>> row(9),col(9);
        map<pair<int, int>, unordered_map<int, bool>> box;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                row[i][board[i][j] - '0'] = true;
                col[j][board[i][j] - '0'] = true;
                box[{i / 3, j / 3}][board[i][j] - '0'] = true;
            }
        }
        bool found = false;
        helper(0, 0, board, row, col, box, found);
        return;
    }
};