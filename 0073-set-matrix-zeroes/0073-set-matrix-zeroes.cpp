class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)return;
        int m = matrix[0].size();
        unordered_map<int, bool> row, col;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(unordered_map<int, bool>:: iterator it = row.begin(); it != row.end(); it++){
            for(int i = 0; i < m; i++){
                matrix[it->first][i] = 0;
            }
        }

        for(unordered_map<int, bool>:: iterator it = col.begin(); it != col.end(); it++){
            for(int i = 0; i < n; i++){
                matrix[i][it->first] = 0;
            }
        }

        return;
    }
};