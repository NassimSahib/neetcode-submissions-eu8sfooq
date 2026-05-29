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
        // Finding the middle and Cut the list in two
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        // Inversing the second half
        ListNode* reversePrev = nullptr;
        ListNode* curr = slow;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = reversePrev;
            reversePrev = curr;
            curr = next;
        }

        // Merging the two lists
        ListNode* first = head;
        ListNode* second = reversePrev;
        while (first && second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            if (firstNext) {
                second->next = firstNext;
                }
            

            first = firstNext;
            second = secondNext;
        }
    }
};
