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
    int getLength(ListNode* head, int n){
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head, n);
        int countFromStart = length - n;
        int it = 1;
        ListNode* temp = head;
        while(temp != NULL){
            if(countFromStart == 0){
                head = head->next;
                break;
            }
            else if(it == countFromStart){
                temp->next = temp->next->next;
                break;
            }
            it++;
            temp = temp->next;
        }
        return head;
    }
};
