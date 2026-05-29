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
    void reorderList(ListNode* head) {
        vector<ListNode*> node;
        ListNode* it = head;

        while(it){
            node.push_back(it);
            it = it->next;
        }

        ListNode* temp = head;
        int start = 0, end = node.size()-1;
        while(start <= end){
            temp->next = node[start];
            start++;
            temp = temp->next;
            temp->next = node[end];
            end--;
            temp = temp->next;
        }
        temp->next = nullptr; 
        head = head->next;
    }
};
