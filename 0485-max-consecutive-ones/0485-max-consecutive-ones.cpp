class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                curr++;
            }
            else{    
                result = max(result, curr);
                curr = 0;
            } 
        }
        return max(curr, result);
    }
};