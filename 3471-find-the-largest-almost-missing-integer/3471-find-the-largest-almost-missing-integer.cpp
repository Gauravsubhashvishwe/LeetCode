class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        if(k == n){
            int max_v = -1;
            for(int num : nums){
                max_v = max(max_v, num);
            }
            return max_v;
        }

        if(k == 1){
            int max_v = -1;
            for(auto& pair: freq){
                if(pair.second == 1){
                    max_v = max(max_v, pair.first);
                }
            }
            return max_v;
        }

        int max_v = -1;
        if(freq[nums[0]] == 1){
            max_v = max(max_v, nums[0]);
        }
        if(freq[nums[n - 1]] == 1){
            max_v = max(max_v, nums[n - 1]);
        }
        return max_v;
    }
};