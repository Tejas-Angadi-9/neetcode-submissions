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
        vector<ListNode*> nodes;
        ListNode* node = head;

        while(node){
            nodes.push_back(node);
            node = node->next;
        }

        ListNode* temp = head;
        int start = 0, end = nodes.size()-1;
        while(start <= end){
            temp->next = nodes[start];
            start++;
            temp = temp->next;
            temp->next = nodes[end];
            end--;
            temp = temp->next;
        }
        temp->next = nullptr; 
        head = head->next;
    }
};
