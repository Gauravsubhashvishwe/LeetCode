class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), [](int a, int b){return a > b;});
        sort(discounts.begin(), discounts.end(), [](int a, int b){return a > b;});
        int n = prices.size();
        int m = discounts.size();
        double result = 0.0;
        for(int i = 0; i < n; i++){
            if(i < m){
                result += prices[i] * (100.0 - discounts[i]) / 100;
            }
            else result += prices[i];
        }
        return result;
    }
};