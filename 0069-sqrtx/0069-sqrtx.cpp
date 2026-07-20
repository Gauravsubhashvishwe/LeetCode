class Solution {
    int helper(int srt, int lst, int &x){
        if(srt > lst)return lst;
        long long mid = srt + (lst - srt) / 2;
        if(mid * mid == x)return mid;
        else if(mid * mid < x) return helper(mid + 1, lst, x);
        else return helper(srt, mid - 1, x);
    }
public:
    int mySqrt(int x) {
        if(x < 2)return x;

       return helper(1, x / 2, x); 
    }
};