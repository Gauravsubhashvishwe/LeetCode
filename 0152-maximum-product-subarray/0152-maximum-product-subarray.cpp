class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long mxpr = nums[0];
	    long long prod = nums[0];
	    long long mipr = nums[0];
	    for(int i = 1;i<n;i++){
            if(mxpr == 0){
                mxpr = 1;
                mipr = 1;
            }
	        if(nums[i]<0){
	            swap(mxpr,mipr);
	        }
	        mxpr = max((long long)nums[i],mxpr*nums[i]);
	        mipr = min((long long)nums[i],mipr*nums[i]);
	        prod = max(prod,mxpr);
	    }
	    return (int)prod;
    }
};