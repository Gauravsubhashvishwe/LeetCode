/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)return root;
        queue<Node*> level;
        level.push(root);
        Node* head = root;
        Node* temp = NULL;
        while(!level.empty()){
            int n = level.size();
            for(int i = 0; i < n; i++){
                Node* front = level.front();
                level.pop();
                if(front->left != NULL){
                    level.push(front->left);
                }
                if(front->right != NULL){
                    level.push(front->right);
                }
                if(temp != NULL){
                    temp->next = front;
                }
                temp = front;
            }
            temp->next = NULL;
            temp = NULL;
        }
        return head;
    }
};