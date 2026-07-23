class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == divisor)return 1;
        bool pos = (dividend < 0 == divisor < 0);
        long long a(abs((long long)dividend)), b(abs((long long)divisor));
        long long result = 0;
        while(a >= b){
            short q = 0;
            while(a > (b << (q + 1))) q++;
            result += (1LL << q);
            a -= (b << q);
        }
        if(result > INT_MAX){
            return pos? INT_MAX: INT_MIN;
        }
        return pos? result : -result;

    }
};