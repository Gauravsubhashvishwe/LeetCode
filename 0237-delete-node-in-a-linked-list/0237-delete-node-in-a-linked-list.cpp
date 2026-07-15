/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL)return;
        else if(node->next == NULL){
            delete node;
            node = nullptr;
        }
        else{
            node->val = node->next->val;
            ListNode* todelete = node->next;
            node->next = node->next->next;
            delete todelete;
            todelete = nullptr;
        }
        return;
    }
};