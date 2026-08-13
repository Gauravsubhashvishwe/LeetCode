class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> visit;
        for(int num : nums){
            visit.insert(num);
        }
        int curr = 1;
        while(visit.count(curr))curr++;
        return curr;
    }
};