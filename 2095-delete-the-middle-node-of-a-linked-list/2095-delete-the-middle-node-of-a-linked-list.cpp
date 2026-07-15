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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            // delete head;
            return nullptr;
        }
        else if(head->next->next == nullptr){
            // delete head->next;
            head->next = nullptr;
            return head;
        }
        ListNode *slw(head), *fst(head), *prev(nullptr);
        while(fst != nullptr && fst->next != nullptr){
            prev = slw;
            slw = slw->next;
            fst = fst->next->next;
        }
        prev->next = slw->next;
        // delete slw;
        return head;
    }
};