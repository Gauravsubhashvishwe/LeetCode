class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int curr = 0;
        vector<int> l_max;
        for(int h : height){
            l_max.push_back(curr);
            curr = max(curr, h);
        }
        l_max.push_back(0);
        int result = 0;
        curr = 0;
        for(int i = n - 1; i >= 0; i--){
            int traped = (min(curr, l_max[i]) - height[i]);
            if(traped >= 0) result += traped;
            curr = max(curr, height[i]);
        }
        return result;
    }
};