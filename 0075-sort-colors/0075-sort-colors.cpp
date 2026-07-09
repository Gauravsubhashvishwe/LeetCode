class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int k = -1;
        int j = n;
        while(i < j){
            if(nums[i] == 0){
                k++;
                swap(nums[i], nums[k]);
                i++;
            }
            else if(nums[i] == 2){
                j--;
                swap(nums[i], nums[j]);
            }
            else{
                i++;
            }
        }
        return;
    }
};