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
    
    void reverse(ListNode* &prev,ListNode* &current){
        if(current == NULL){
            return;
        }
        
        ListNode* forward = current->next;
        current -> next = prev;
        prev = current;
        current = forward;
        reverse(prev,current);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        
        reverse(prev,current);
        return prev;
    }
};
