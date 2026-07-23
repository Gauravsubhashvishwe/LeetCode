class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3)return -1;
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(result - target) > abs(sum - target)){
                    result = sum;
                }
                if(sum > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return result;
    }
};