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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return false;
        }
        ListNode* slower = head;
        ListNode* faster = head -> next;
        
        while(faster != NULL){
            if(faster == slower){
                return true;
            }
            faster = faster -> next;
            if(faster){
                faster = faster -> next;
            }
            slower = slower -> next;
        }
        return false;
    }
};
