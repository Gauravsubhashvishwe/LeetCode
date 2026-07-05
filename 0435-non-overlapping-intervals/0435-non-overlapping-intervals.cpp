class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int prev = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                cnt++;
            }
        }
        return n - cnt;
    }
};