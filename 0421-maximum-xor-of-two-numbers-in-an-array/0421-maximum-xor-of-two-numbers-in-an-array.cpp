class Solution {
    class trie{
        class node{
        public: 
            node* next[2];
            node(){
                next[0] = NULL;
                next[1] = NULL;
            }
        };
        node* head;
    public:
        trie(){
            head = new node();
        }

        void insert(int num){
            node* temp = head;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(temp->next[bit] == nullptr){
                    temp->next[bit] = new node();
                }
                temp = temp->next[bit];
            }
            return;
        }

        int xor_max(int num){
            node* temp = head;
            int result = 0;
            for(int i = 31; i >= 0; i--){
                int bit = ((num >> i) & 1);
                int req = 1 - bit;
                if(temp->next[req] != NULL){
                    result |= (1U << i);
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
    int findMaximumXOR(vector<int>& nums) {
        trie* head = new trie();
        for(auto num : nums){
            head->insert(num);
        }
        int max_xor = 0;
        for(auto num : nums){
            max_xor = max(max_xor, head->xor_max(num));
        }
        return max_xor;
    }
};