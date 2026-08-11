class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        int sum = nums[0];
        if(n == 1)return sum + 1;
        int i = 1;
        for( ; i < n; i++){
            if(!(nums[i] == nums[i - 1] + 1)){
                break;
            }
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        for(i = 0; i < n; i++){
            if(nums[i] == sum)sum++;
            else if(nums[i] > sum)break;
        }
        return sum;
    }
};