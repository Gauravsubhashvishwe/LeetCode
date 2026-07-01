class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int creach = 0;
        int cnt = 0;
        for(int i = 0; i < n && i <= creach;){
            if(creach >= n - 1)return cnt;
            int reach = creach;
            while(i <= creach && i < n){
                reach = max(reach, i + nums[i]);
                i++;
            }
            cnt++;
            creach = reach;
        }
        if(creach >= n - 1)return cnt;
        return -1;
    }
};