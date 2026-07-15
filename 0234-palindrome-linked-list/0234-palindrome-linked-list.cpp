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
    ListNode *temp1, *temp2;
    pair<bool, ListNode*> helper(ListNode* node){
        if(node == temp1){
            if(temp2->next == nullptr){
                return {true, node->next};
            }
            else{
                if(node->val == node->next->val){
                    return {true, node->next->next};
                }
                else{
                    return {false, node->next->next};
                }
            }
        }
        pair<bool, ListNode*> prev = helper(node->next);
        if(!prev.first || prev.second->val != node->val)return {false, prev.second->next};
        else return {true, prev.second->next};
    }
public:
    bool isPalindrome(ListNode* head) {
        temp1 = head;
        temp2 = head;
        if(head == nullptr)return true;
        if(head->next == nullptr)return true;
        while(temp2->next != NULL && temp2->next->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
        return helper(head).first;
    }
};