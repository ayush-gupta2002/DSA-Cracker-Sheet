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
    
    void reverse(ListNode* &start,ListNode* &end){
        ListNode* current = start;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        
        while(prev != end){
            forward = current -> next;
            current -> next = prev;
            prev = current;
            current = forward;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k ==1){
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* beforeStart = dummy;
        ListNode* end = head;
        int i = 0;
        while(end != NULL){
            i++;
            if(i%k==0){
                ListNode* start = beforeStart -> next;
                ListNode* afterEnd = end -> next;
                reverse(start,end);
                beforeStart -> next = end;
                start -> next = afterEnd;
                beforeStart = start;
                end = afterEnd;
            }
            else{
                end = end -> next;
            }
        }
        return dummy->next;
    }
};
