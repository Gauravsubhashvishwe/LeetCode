class Solution {

    bool is_safe(int i, int j, vector<string> &board){
        for(int k = 0; k < i; k++){
            if(board[k][j] == 'Q')return false;
        }
        int l = i - 1;
        int m = j - 1;
        while(l >= 0 && m >= 0){
            if(board[l][m] == 'Q')return false;
            l--;
            m--;
        }
        l = i - 1;
        m = j + 1;
        while(l >= 0 && m < board.size()){
            if(board[l][m] == 'Q')return false;
            l--;
            m++;
        }
        return true;
    }

    void helper(int l, vector<string> &board, vector<vector<string>> &result){
        if(l == board.size()){
            result.push_back(board);
            return;
        }
        for(int i = 0; i < board.size(); i++){
            if(is_safe(l, i, board)){
                board[l][i] = 'Q';
                helper(l + 1, board, result);
                board[l][i] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i = 0; i < n; i++){
            string l = "";
            for(int j = 0; j < n; j++){
                l += '.';
            }
            board.push_back(l);
        }
        vector<vector<string>> result;
        helper(0, board, result);
        return result;
    }
};