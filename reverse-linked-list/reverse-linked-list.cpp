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
    ListNode* solve(ListNode* node,ListNode* prev,ListNode* front){
        if(node==NULL){
            return prev;
        }
        front=node->next;
        ListNode* ptr=node->next; 
        node->next = prev;
        prev = node;
        return solve(ptr,prev,front);
    }
    ListNode* reverseList(ListNode* head) {
        return solve(head,NULL,NULL);
    }
};