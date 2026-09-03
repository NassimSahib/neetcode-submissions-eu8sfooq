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
        if (!head || !head->next) return;
        // Split in half the list, generating l1 and l2
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;

        // Reversing l2
        ListNode* currL2 = l2;
        ListNode* prev = nullptr;

        while (currL2) {
            ListNode* next = currL2->next;
            currL2->next = prev;
            prev = currL2;
            currL2 = next;
        }

        ListNode* reversedL2 = prev;

        // Joining the two lists

        while (l1 && reversedL2) {
            ListNode* nextL1 = l1->next;
            ListNode* nextL2 = reversedL2->next;

            l1->next  = reversedL2;

            if (nextL1 == nullptr) {
                break;
            }
            reversedL2->next = nextL1;

            l1 = nextL1;
            reversedL2 = nextL2;

        }       
    }
};
