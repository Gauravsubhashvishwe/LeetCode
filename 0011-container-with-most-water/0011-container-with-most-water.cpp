class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int result = 0;
        while(i < j){
            int curr = min(height[i], height[j]) * (j - i);
            result = max(result, curr);
            if(height[i] > height[j])j--;
            else i++;
        }
        return result;
    }
};