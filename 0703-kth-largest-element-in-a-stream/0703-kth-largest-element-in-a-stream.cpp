auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> data;
    int l;
public:
    KthLargest(int k, vector<int>& nums) {
        l = k;
        for(int val : nums) {
            if(data.size() < l) {
                data.push(val);
            }
            else if(val > data.top()) {
                data.pop();
                data.push(val);
            }
        }
    }
    
    int add(int val) {
        if(data.size() < l){
            data.push(val);
        }
        else if(data.top() < val){
            data.pop();
            data.push(val);
        }
        return data.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */