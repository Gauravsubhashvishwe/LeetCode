class KthLargest {
    priority_queue<int, vector<int>, greater<int>> data;
    int l;
public:
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        l = k;
        for(int i = 0; i < n; i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        data.push(val);
        if(data.size() > l){
            data.pop();
        }
        return data.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */