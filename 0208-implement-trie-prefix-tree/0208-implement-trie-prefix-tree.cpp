class Trie {
    class node{
    public:
        bool end;
        node* next[26];

        node(){
            end = false;
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
    };
    node* head;
public:
    Trie() {
        head = new node();
    }
    
    void insert(string word) {
        node* temp = head;
        for(int i = 0; i < word.size(); i++){
            if(temp->next[word[i] - 'a'] == NULL){
                temp->next[word[i] - 'a'] = new node();
            }
            temp = temp->next[word[i] - 'a'];
        }
        temp->end = true;
        return;
    }
    
    bool search(string word) {
        int n = word.size();
        node* temp = head;
        for(int i = 0; i < n; i++){
            if(temp->next[word[i] - 'a'] == NULL)return false;
            temp = temp->next[word[i] - 'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        node* temp = head;
        for(int i = 0; i < n; i++){
            if(temp->next[prefix[i] - 'a'] == NULL)return false;
            temp = temp->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */