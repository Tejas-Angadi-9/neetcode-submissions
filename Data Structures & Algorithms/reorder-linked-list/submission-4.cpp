class Solution {
public:
    ListNode* findEndOfFirstHalf(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* secondHalfHead = findEndOfFirstHalf(head);
        ListNode* reversedHead = reverseList(secondHalfHead);

        ListNode* firstPtr = head;
        ListNode* secondPtr = reversedHead;

        while (firstPtr && secondPtr) {
            ListNode* firstNext = firstPtr->next;
            ListNode* secondNext = secondPtr->next;

            firstPtr->next = secondPtr;
            secondPtr->next = firstNext;

            firstPtr = firstNext;
            secondPtr = secondNext;
        }
    }
};