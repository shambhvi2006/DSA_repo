#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* findIntersectionNode(ListNode *A, ListNode *B, int difference) {
    while (difference > 0) {
        if (!A) return nullptr;   // prevent null dereference
        A = A->next;
        difference--;
    }
    while (A != nullptr && B != nullptr) {
        if (A == B) return A;
        A = A->next;
        B = B->next;
    }
    return nullptr;
}

ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    if (!A || !B) return nullptr;

    int firstLength = 0;
    ListNode* firstCurrNode = A;
    while (firstCurrNode != nullptr) {
        firstLength++;
        firstCurrNode = firstCurrNode->next;
    }

    int secondLength = 0;
    ListNode* secondCurrNode = B;
    while (secondCurrNode != nullptr) {
        secondLength++;
        secondCurrNode = secondCurrNode->next;
    }

    if (firstLength < secondLength) {
        return findIntersectionNode(B, A, secondLength - firstLength);
    } else {
        return findIntersectionNode(A, B, firstLength - secondLength);
    }
}

int main() {
    // Create two linked lists with intersection
    // List A: 1 -> 2 -> 3 \
    //                       -> 7 -> 8
    // List B:       4 -> 5 /
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    ListNode* b1 = new ListNode(4);
    ListNode* b2 = new ListNode(5);
    ListNode* c1 = new ListNode(7);
    ListNode* c2 = new ListNode(8);

    // Build first list
    a1->next = a2;
    a2->next = a3;
    a3->next = c1;

    // Build second list
    b1->next = b2;
    b2->next = c1;

    // Common tail
    c1->next = c2;

    ListNode* intersection = getIntersectionNode(a1, b1);
    if (intersection != nullptr) {
        cout << "Intersection found at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
