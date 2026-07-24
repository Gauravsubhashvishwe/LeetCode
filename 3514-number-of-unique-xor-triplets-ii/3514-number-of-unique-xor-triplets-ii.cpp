class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int l = 2048;
        vector<bool> t_xor(l + 1, false);
        vector<bool> th_xor(l + 1, false);

        for(int &fnum : nums){
            for(int &snum : nums){
                t_xor[fnum ^ snum] = true;
            }
        }
        int result = 0;
        for(int &num : nums){
            for(int i = 0; i <= l; i++){
                if(t_xor[i]){
                    int th_x = num ^ i;
                    if(!th_xor[th_x]){
                        result++;
                        th_xor[th_x] = true;
                    }
                }
            }
        }
        return result;
    }
};