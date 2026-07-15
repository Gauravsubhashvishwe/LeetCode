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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode *even(nullptr), *odd(nullptr), *temp(head), *newh(nullptr);

        while(temp != NULL && temp->next != NULL){
            if(odd == nullptr){
                odd = temp;
                even = temp->next;
                newh = temp->next;
            }
            else{
                odd->next = temp;
                even->next = temp->next;
                odd = odd->next;
                even = even->next;
            }
            temp = temp->next->next;
        }
        if(temp != NULL){
            odd->next = temp;
            odd = odd->next;
        }
        even->next = nullptr;
        odd->next = newh;
        return head;
    }
};