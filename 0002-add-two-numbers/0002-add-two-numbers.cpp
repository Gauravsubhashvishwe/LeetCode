/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(l1 != NULL && l2 != NULL){
            int d = l1->val + l2->val + c;
            c = d / 10;
            if(head == nullptr){
                head = new ListNode(d % 10);
                temp = head;
            }
            else{
                temp->next = new ListNode(d % 10);
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int d = l1->val + c;
            if(head == nullptr){
                return l1;
            }
            c = d / 10;
            temp->next = new ListNode(d % 10);
            temp = temp->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int d = l2->val + c;
            if(head == nullptr){
                return l2;
            }
            c = d / 10;
            temp->next = new ListNode(d % 10);
            temp = temp->next;
            l2 = l2->next;
        }
        if(c == 1){
            temp->next = new ListNode(1);
        }
        return head;
    }
};