class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2)return nums.size();
        int result = 0;
        for(int num : nums){
            result |= num;
        }
        result++;
        return result;
    }
};