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
    
    ListNode* floydDetection(ListNode *head){
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && slow != NULL){
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
            }
            slow = slow -> next;
            if(fast == slow){
                return fast;
            }
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* intersection = floydDetection(head);
        if(intersection){
            ListNode* slow = head;
            while (slow != intersection){
                slow = slow -> next;
                intersection = intersection -> next;
            }
            return intersection;
        }
        else{
            return NULL;
        }
    }
};
