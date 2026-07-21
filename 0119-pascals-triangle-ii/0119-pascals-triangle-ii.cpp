class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<vector<int>> pas_t;
        pas_t.push_back({1});
        if(n == 0){
            return pas_t[0];
        }
        pas_t.push_back({1, 1});
        if(n == 1){
            return pas_t[1];
        }
        for(int i = 2; i <= rowIndex; i++){
            pas_t.push_back({1});
            for(int j = 1; j < i; j++){
                pas_t[i].push_back(pas_t[i - 1][j] + pas_t[i - 1][j - 1]);
            }
            pas_t[i].push_back(1);
        }
        return pas_t[n];
    }
};