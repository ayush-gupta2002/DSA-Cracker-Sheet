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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while(current != NULL){
            ListNode* forward = current -> next;
            
            if(forward){
                if(forward -> val == current -> val){
                    current -> next = forward -> next;
                    forward -> next = NULL;
                    delete (forward);
                }
                else{
                    current = forward;
                }
            }
            else{
                current = forward;
            }
        }
        return head;
    }
};
