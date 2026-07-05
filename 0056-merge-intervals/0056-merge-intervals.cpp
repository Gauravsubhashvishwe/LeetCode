class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int m = 1;
        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(result[m - 1][1] < intervals[i][0]){
                result.push_back(intervals[i]);
                m++;
            }
            else if(result[m - 1][1] > intervals[i][1]);
            else{
                result[m - 1][1] = intervals[i][1];
            }
        }
        return result;
    }
};