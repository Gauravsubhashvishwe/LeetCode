class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        if(m == 0)return {{}};
        int n = image[0].size();

        vector<int> it = {-1, 0, 0, 1};
        vector<int> jt = {0, -1, 1, 0};

        vector<vector<int>> result(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[i][j] = image[i][j];
            }
        }

        int int_c = image[sr][sc];
        result[sr][sc] = color;
        if(int_c == color)return result;

        queue<pair<int, int>> trav;
        trav.push({sr, sc});
        while(!trav.empty()){
            auto [i, j] = trav.front();
            trav.pop();

            for(int k = 0; k < 4; k++){
                if((i + it[k] >= 0 && i + it[k] < m) && (j + jt[k] >= 0 && j + jt[k] < n) && result[i + it[k]][j + jt[k]] == int_c){
                    trav.push({i + it[k], j + jt[k]});
                    result[i + it[k]][j + jt[k]] = color;
                }
            }
        }

        return result;
    }
};