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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = current -> next;
        
        while(current){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    void insertAtTail(int digit,ListNode* &head,ListNode* &tail){
        ListNode* temp = new ListNode(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    ListNode* add(ListNode* l1,ListNode* l2){
        int carry = 0;
        ListNode* resHead = NULL;
        ListNode* resTail = resHead;
        while(l1 || l2 || carry!=0){
            int val1 = 0;
            if(l1){
                val1 = l1->val;
            }
            int val2 = 0;
            if(l2){
                val2 = l2->val;
            }
            
            int sum = val1 + val2+carry;
            int digit = sum % 10;
            insertAtTail(digit,resHead,resTail);
            carry = sum / 10;
            if(l1){
                l1 = l1 -> next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        
        return resHead;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = add(l1,l2);
        return ans;
    }
};
