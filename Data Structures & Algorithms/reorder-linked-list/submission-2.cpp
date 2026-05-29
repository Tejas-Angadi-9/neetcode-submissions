class Solution {
public:
    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* secondHalf = getMiddleNode(head);
        ListNode* middle = reverseLinkedList(secondHalf);

        ListNode* iterator = head;

        while (iterator && middle) {
            ListNode* iterNext = iterator->next;
            ListNode* midNext = middle->next;

            iterator->next = middle;
            middle->next = iterNext;

            iterator = iterNext;
            middle = midNext;
        }
    }
};