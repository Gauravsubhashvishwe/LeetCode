class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)return n;
        unordered_map<int, int> freq;
        int j = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[j]]--;
                j++;
            }
            result = max(result, i - j + 1);
        }
        return result;
    }
};