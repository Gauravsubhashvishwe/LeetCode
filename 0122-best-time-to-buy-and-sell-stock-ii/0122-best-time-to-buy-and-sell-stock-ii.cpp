class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_t = prices[0];
        int max_p = 0;
        for(auto price : prices){
            if(min_t < price){
                max_p += (price - min_t);
            }
            min_t = price;
            
        }
        return max_p;
    }
};