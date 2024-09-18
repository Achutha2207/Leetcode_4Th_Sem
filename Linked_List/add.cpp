#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class for adding two numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *current = dummyHead;
        int carry = 0;

        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }

        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return dummyHead->next;
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* node) {
    while (node != NULL) {
        cout << node->val;
        if (node->next != NULL) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example: two numbers represented by linked lists
    int arr1[] = {3, 2, 1};  // Represents number 123
    int arr2[] = {6, 5, 4};  // Represents number 456

    // Create linked lists
    ListNode* l1 = createLinkedList(arr1, 3);
    ListNode* l2 = createLinkedList(arr2, 3);

    // Print the input linked lists
    cout << "List 1: ";
    printLinkedList(l1);
    cout << "List 2: ";
    printLinkedList(l2);

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    cout << "Sum: ";
    printLinkedList(result);

    return 0;
}

