class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        if(n < 3)return result;

        sort(nums.begin(), nums.end());
        for(int k = 0; k < n - 2; k++){
            if(nums[k] > 0)break;

            if(k > 0 && nums[k] == nums[k - 1])continue;

            int i = k + 1;
            int j = n - 1;

            while(i < j){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    result.push_back({nums[k], nums[i], nums[j]});

                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;

                    i++;
                    j--;
                }
                else if(sum < 0){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return result;
    }
};