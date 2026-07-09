class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> pres;
        for(int &num : nums){
            pres[num] = true;
        }
        int i = 0;
        map<int, bool>::iterator it = pres.begin();
        for( ; it != pres.end(); it++){
            nums[i] = it->first;
            i++;
        }
        return i;
    }
};