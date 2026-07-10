class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        
        if(n < 4)return result;

        sort(nums.begin(), nums.end());
        for(int l = 0; l < n - 3; l++){
            if(l > 0 && nums[l] == nums[l - 1])continue;
            for(int k = l + 1; k < n - 2; k++){

                if(k > l + 1 && nums[k] == nums[k - 1]) continue;
                int i = k + 1;
                int j = n - 1;

                while(i < j){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        result.push_back({nums[l], nums[k], nums[i], nums[j]});

                        while (i < j && nums[i] == nums[i + 1]) i++;
                        while (i < j && nums[j] == nums[j - 1]) j--;

                        i++;
                        j--;
                    }
                    else if(sum < target){
                        i++;
                    }
                    else{
                        j--;
                    }
                }
            }
        }
        return result;
    }
};