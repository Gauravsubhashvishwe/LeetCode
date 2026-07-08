class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_t = 1e9 + 7;
        int max_p = 0;
        for(auto price : prices){
            min_t = min(min_t, price);
            max_p = max(max_p, price - min_t);
        }
        return max_p;
    }
};