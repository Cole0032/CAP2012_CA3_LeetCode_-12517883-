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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // Step 1: Find the kth node from groupPrev
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break; // Fewer than k nodes remain

            ListNode* groupNext = kth->next;

            // Step 2: Reverse the k nodes in-place
            // Initialize prev to groupNext so the reversed group's tail links directly to groupNext
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }

            // Step 3: Reconnect previous part of the list to the new head (kth)
            ListNode* groupTail = groupPrev->next; // Original head is now the tail
            groupPrev->next = kth;
            groupPrev = groupTail;
        }

        return dummy.next;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            --k;
        }
        return curr;
    }
};
