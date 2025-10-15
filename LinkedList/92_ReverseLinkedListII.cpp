class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextN = nullptr;

        while (curr != nullptr) {
            nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* end = start;

        for (int i = left; i < right; i++) {
            end = end->next;
        }

        ListNode* nextNode = end->next;
        end->next = nullptr;

        prev->next = rev(start);
        start->next = nextNode;

        head = dummy->next;
        delete dummy;
        return head;
    }
};