class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        int j = 0;
        for(int i = 31; i >= 0; i--){
            if((n >> i ) & 1){
                result |= (1 << j);
            }
            j++;
        }
        return result;
    }
};