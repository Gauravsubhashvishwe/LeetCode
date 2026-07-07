class Solution {
    class trie{
        class node{
        public:
            node* next[2];

            node(){
                next[0] = nullptr;
                next[1] = nullptr;
            }
        };
        node* head;
    public:
        trie(){
            head = new node();
        }
        
        void insert(int num){
            node* temp = head;
            for(int i = 30; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(temp->next[bit] == nullptr){
                    temp->next[bit] = new node();
                }
                temp = temp->next[bit];
            }
            return;
        }
        
        int max_xor(int num){
            node* temp = head;
            int result = 0;
            for(int i = 30; i >= 0; i--){
                int bit = (num >> i) & 1;
                int req = 1 - bit;
                if(temp->next[req] != nullptr){
                    result |= (1 << i);
                    temp = temp->next[req];
                }
                else{
                    temp = temp->next[bit];
                }
            }
            return result;
        }

    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for(int i = 0; i < n; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        sort(nums.begin(), nums.end());

        vector<int> result(n, -1);
        int j = 0;
        int m = nums.size();
        trie* head = new trie();

        for(auto queri : queries){
            while(j < m && queri[1] >= nums[j]){
                head->insert(nums[j]);
                j++;
            }
            int res;
            if(j == 0){
                res = -1;
            }
            else{
                res = head->max_xor(queri[0]);
            }
            result[queri[2]] = res;
        }
        return result;
    }
};