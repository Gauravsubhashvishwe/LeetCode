class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(2, 0);
        int n = bills.size();

        for(int i = 0; i < n; i++){
            if(bills[i] == 5)cash[0]++;
            else if(bills[i] == 10){
                if(cash[0] < 1) return false;
                cash[0]--;
                cash[1]++;
            }
            else{
                if(cash[1] > 0 && cash[0] > 0){
                    cash[1]--;
                    cash[0]--;
                    continue;
                }
                else if(cash[0] > 2){
                    cash[0] -= 3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};