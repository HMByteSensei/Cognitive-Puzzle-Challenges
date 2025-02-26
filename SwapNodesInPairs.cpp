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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        head = tmp;
        ListNode *headTmp = swapPairs(head->next->next);
        if(head->next->next != nullptr && head->next != nullptr) {
            head->next->next = headTmp;
        }
        return head;
        
    }
};
