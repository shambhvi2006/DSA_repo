#include <iostream>
using namespace std;
class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
	ListNode* currentNode = head;
	int totalNodes = 0;
	while (currentNode != NULL && totalNodes < k) {
		currentNode = currentNode->next;
		totalNodes++;
	}
	if (totalNodes < k) {
		return head;
	}
	currentNode = head;
	ListNode* prevNode = NULL;
	ListNode* nextNode;
	int nodeCount = 0;
	while (nodeCount < k) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
		nodeCount++;
	}
	head->next = reverseLinkedListKGroup(nextNode, k);
	return prevNode;
}
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    int k = 3; // Reverse in groups of 3

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedListKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}