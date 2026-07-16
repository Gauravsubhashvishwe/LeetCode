class Solution {
    long long mod = 1000000007;
    long long myPow(long long x, long long n) {
        long long result = 1;
        while(n > 0){
            if(n % 2 == 1){
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        if(n == 0)return 1;
        long long even = myPow(5, (n + 1) / 2);
        long long odd = myPow(4, n / 2);
        long long result = (even * odd) % mod;
        return (int)result;
    }
};