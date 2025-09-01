#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

// Function to reverse in groups of k (swapping data only)
void reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return;

    Node* groupStart = head;

    while (groupStart) {
        // Find the end of this group (could be < k nodes at the end)
        Node* groupEnd = groupStart;
        int count = 1;
        while (count < k && groupEnd->next) {
            groupEnd = groupEnd->next;
            count++;
        }

        // Two pointer technique to swap data
        Node* start = groupStart;
        Node* end = groupEnd;
        while (start != end && start->prev != end) {
            swap(start->data, end->data);
            start = start->next;
            end = end->prev;
        }

        // Move groupStart to the next group
        groupStart = groupEnd->next;
    }
}

// Utility function to print the doubly linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Example: create DLL 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 7; i++) {
        temp->next = new Node(i);
        temp->next->prev = temp;
        temp = temp->next;
    }

    cout << "Original list:\n";
    printList(head);

    int k = 3;
    reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
