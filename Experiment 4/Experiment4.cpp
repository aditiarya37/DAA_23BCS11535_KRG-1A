#include <iostream>
using namespace std;
class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int data) {
        this->data = data;
        prev = next = nullptr;
    }
};
class DoublyLinkedList {
public:
    DoublyNode* head;
    DoublyLinkedList() { head = nullptr; }
    void insertAtBeginning(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void insertAtEnd(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteAtBeginning() {
        if (head == nullptr) return;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
    }
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            head = nullptr;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->prev->next = nullptr;
    }
    void display() {
        DoublyNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class CircularNode {
public:
    int data;
    CircularNode* next;
    CircularNode(int data) {
        this->data = data;
        next = nullptr;
    }
};
class CircularLinkedList {
public:
    CircularNode* head;
    CircularLinkedList() { head = nullptr; }
    void insertAtBeginning(int data) {
        CircularNode* newNode = new CircularNode(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CircularNode* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int data) {
        CircularNode* newNode = new CircularNode(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CircularNode* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void deleteAtBeginning() {
        if (head == nullptr) return;
        if (head->next == head) {
            head = nullptr;
            return;
        }
        CircularNode* temp = head;
        while (temp->next != head) temp = temp->next;
        head = head->next;
        temp->next = head;
    }
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == head) {
            head = nullptr;
            return;
        }
        CircularNode* temp = head;
        CircularNode* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    void display() {
        if (head == nullptr) return;
        CircularNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    cout << "Doubly Linked List:" << endl;
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();
    dll.deleteAtBeginning();
    dll.display();
    dll.deleteAtEnd();
    dll.display();
    cout << "\nCircular Linked List:" << endl;
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteAtBeginning();
    cll.display();
    cll.deleteAtEnd();
    cll.display();
    return 0;
}
