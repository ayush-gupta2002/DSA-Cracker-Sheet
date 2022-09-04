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
    ListNode* middleNode(ListNode* head) {
        if(head -> next == NULL || head == NULL){
            return head;
        }
        if(head -> next -> next == NULL){
            return head -> next;
        }
        ListNode* faster = head->next;
        ListNode* slower = head;
        while(faster!= NULL){
            faster = faster -> next;
            if(faster != NULL){
                faster = faster -> next;
            }
            slower = slower -> next;
        }
        return slower;
    }
};
