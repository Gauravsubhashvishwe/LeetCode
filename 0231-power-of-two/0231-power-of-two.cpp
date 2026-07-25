class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool pres = false;
        if(n == 0 || n < 0)return false;
        for(int i = 0; i < 31; i++){
            if(n >> i & 1){
                if(!pres){
                    pres = true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};