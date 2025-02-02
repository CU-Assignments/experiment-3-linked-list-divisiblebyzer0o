#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (head) {
        bool duplicate = false;
        while (head->next && head->val == head->next->val) {
            head = head->next;
            duplicate = true;
        }
        if (duplicate)
            prev->next = head->next;
        else
            prev = prev->next;
        head = head->next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    
    ListNode* result = deleteDuplicates(head);
    printList(result);

    return 0;
}
