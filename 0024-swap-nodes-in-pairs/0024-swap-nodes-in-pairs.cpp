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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == NULL)return head;
        ListNode* n_tell = swapPairs(head->next->next);
        ListNode* new_h = head->next;
        new_h->next = head;
        head->next = n_tell;
        return new_h;
    }
};