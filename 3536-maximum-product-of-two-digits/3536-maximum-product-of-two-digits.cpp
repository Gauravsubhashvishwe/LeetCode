class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10, 0);
        while(n > 0){
            freq[n % 10]++;
            n /= 10;
        }
        int n1 = 0;
        int n2 = 0;
        int i = 0;
        for(int j = 9; j >= 0; j--){
            if(freq[j] > 0){
                if(i == 0){
                    n1 = j;
                    freq[j]--;
                    j++;
                    i++;
                }
                else if(i == 1){
                    n2 = j;
                    freq[j]--;
                    j++;
                    i++;
                }
                else break;
            }
        }
        return n1 * n2;
    }
};