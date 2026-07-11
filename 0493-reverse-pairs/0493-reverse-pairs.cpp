class Solution {
    int merge(int srt, int mid, int lst, vector<int> &nums){
        int n = mid - srt + 1;
        int m = lst - mid;
        vector<int> left(nums.begin() + srt, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + lst + 1);
        
        int result = 0;
        int j_count = 0;
        for (int i = 0; i < n; i++) {
            while (j_count < m && left[i] > 2LL * right[j_count]) {
                j_count++;
            }
            result += j_count;
        }

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n && j < m){
            if(left[i] < right[j]){
                nums[k + srt] = left[i];
                i++;
            }
            else{
                nums[k + srt] = right[j];
                j++;
            }
            k++;
        }
        
        while(i < n){
            nums[k + srt] = left[i];
            i++;
            k++;
        }
        
        while(j < m){
            nums[k + srt] = right[j];
            j++;
            k++;
        }
        return result;
    }

    int merge_sort(int srt, int lst, vector<int> &nums){
        if(srt >= lst)return 0;
        int mid = (srt + lst) / 2;
        int left = merge_sort(srt, mid, nums);
        int right = merge_sort(mid + 1, lst, nums);
        int full = merge(srt, mid, lst, nums);
        return (left + right + full);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        int result = merge_sort(0, n - 1, nums);
        return result;
    }
};