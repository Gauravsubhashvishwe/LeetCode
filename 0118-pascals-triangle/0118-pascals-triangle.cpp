class Solution {
    long long fact(int n){
        if(n < 2)return 1;
        return n * fact(n - 1);
    }
    int com(int i, int j){
        return (int)(fact(i)/ (fact(i - j) * fact(j)));
    }
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> pas_t;
        if(n == 0)return pas_t;
        pas_t.push_back({1});
        if(n == 1){
            return pas_t;
        }
        pas_t.push_back({1, 1});
        if(n == 2){
            return pas_t;
        }
        for(int i = 2; i < numRows; i++){
            pas_t.push_back({1});
            for(int j = 1; j < i; j++){
                pas_t[i].push_back(pas_t[i - 1][j] + pas_t[i - 1][j - 1]);
            }
            pas_t[i].push_back(1);
        }
        return pas_t;
    }
};