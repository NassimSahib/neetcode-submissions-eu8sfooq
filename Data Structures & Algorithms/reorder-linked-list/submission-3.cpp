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
        // Let's find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = slow->next;
        slow->next = nullptr;

        // Inverse the second part of the list
        ListNode* curr = secondHead;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* inversedSecond = prev;

        // Now merge the first half with the inversed second
        ListNode* firstHalf = head;

        while (firstHalf && inversedSecond) {
            ListNode* nextFirstHalf = firstHalf->next;
            ListNode* nextInversedSecond = inversedSecond->next;

            firstHalf->next = inversedSecond;
            inversedSecond->next = nextFirstHalf;

            inversedSecond = nextInversedSecond;
            firstHalf = nextFirstHalf;
        }
    }
};
