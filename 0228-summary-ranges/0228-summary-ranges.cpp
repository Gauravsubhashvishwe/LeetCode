class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return {};
        char zr = '0';
        int prev = nums[0];
        vector<string> result;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1] + 1){
                string curr = "";
                curr += (to_string(prev) + "->" + to_string(nums[i - 1]));
                if(prev == nums[i - 1])result.push_back(to_string(nums[i - 1]));
                else{
                    result.push_back(curr);
                }
                prev = nums[i];
            }
        }
        if(prev == nums[n - 1]){
            result.push_back(to_string(nums[n - 1]));
        }
        else{
            string curr = "";
            curr += (to_string(prev) + "->" + to_string(nums[n - 1]));
            result.push_back(curr);
        }
        return result;
    }
};