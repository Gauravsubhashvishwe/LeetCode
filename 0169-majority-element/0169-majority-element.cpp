class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        int key = (n / 2);
        for(unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++){
            if(key < it->second)return it->first;
        }
        return 0;
    }
};