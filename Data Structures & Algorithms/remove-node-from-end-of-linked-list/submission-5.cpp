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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Assign the fast and slow pointers to head
        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fast pointer to n times using a for loop
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        // Check if the fast pointer is null, if yes then return head->next
        if(fast == NULL) return head->next;

        // Run a loop until fast->next != NULL and move fast and slow pointer by 1
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Store the slow->next in a variable as it will be useful when we will be deleting it to free up space
        ListNode* deleteNode = slow->next;

        // Connect slow->next = slow->next->next
        slow->next = slow->next->next;

        // Delete the slow->next node
        delete deleteNode;

        // Return head
        return head; 
    }
};
