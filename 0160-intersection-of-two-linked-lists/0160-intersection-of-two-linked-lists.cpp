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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first(headA), *secd(headB);
        int n1(0), n2(0);
        while(first != nullptr){
            first = first->next;
            n1++;
        }
        while(secd != nullptr){
            secd = secd->next;
            n2++;
        }
        first = headA;
        secd = headB;
        while(n1 > n2){
            first = first->next;
            n1--;
        }
        while(n2 > n1){
            secd = secd->next;
            n2--;
        }

        while(first != nullptr){
            if(first == secd){
                return first;
            }
            first = first->next;
            secd = secd->next;
        }
        return nullptr;
    }
};