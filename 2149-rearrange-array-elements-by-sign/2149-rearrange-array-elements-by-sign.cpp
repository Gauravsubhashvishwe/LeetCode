class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0;
        int j = 0;
        for(int num : nums){
            if(num < 0){
                result[2 * i + 1] = num;
                i++;
            }
            else{
                result[2 * j] = num;
                j++;
            }
        }
        return result;
    }
};