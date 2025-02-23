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
#pragma GCC optimize("03, unroll-loops")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")

static const bool __boost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
} ();

class Solution {
private:
    ListNode* helper(ListNode *head) {
        if(head->next == nullptr) {
            return head;
        }
        ListNode *tmp = helper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        // need recursion
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        return helper(head);
        // iterative
//         if(head == nullptr || head->next == nullptr) {
//             return head;
//         }
        
//         ListNode *tmp = nullptr;
//         ListNode *newHead = head;
//         while(head->next) {
//             tmp = head->next;
//             head->next = tmp->next;
//             tmp->next = newHead;
//             newHead = tmp;
//         }
//         return newHead;
    }
};
