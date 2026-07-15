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
    pair<int, ListNode*> helper(ListNode* node, int n){
        if(node == nullptr)return {0, NULL};
        pair<int, ListNode*> prev = helper(node->next, n);
        if(prev.first + 1 == n){
            delete node;
            return {n + 1, prev.second};
        }
        node->next = prev.second;
        return {prev.first + 1, node};
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n).second;
    }
};