class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != nums[j]){
                nums[j + 1] = nums[i];
                j++;
            }
        }
        return ++j;
    }
};