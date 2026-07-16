class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            N = -1 * N;
            x = 1.0 / x;
        }
        double result = 1.0;
        while(N > 0){
            if(N % 2 == 1){
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        return result;
    }
};