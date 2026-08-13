class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n + 1, false);
        for(int num : nums){
            if(num >= 0 && num <= n){
                visit[num] = true;
            }
        }
        int i = 1;
        for(; i <= n; i++){
            if(!visit[i])break;
        }
        return i;
    }
};