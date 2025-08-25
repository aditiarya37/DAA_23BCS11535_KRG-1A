#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> list;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        list.reserve(size);
    }

    bool isEmpty() {
        return list.empty();
    }

    bool isFull() {
        return (int)list.size() == capacity;
    }

    void push(T item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << item << endl;
            return;
        }
        list.push_back(item);
        cout << item << " pushed into stack." << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return T(); 
        }
        T item = list.back();
        list.pop_back();
        return item;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return T(); 
        }
        return list.back();
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (auto item : list) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();
    cout << "Top element: " << intStack.peek() << endl;

    intStack.pop();
    intStack.display();

    cout << "Is Empty? " << (intStack.isEmpty() ? "true" : "false") << endl;
    cout << "Is Full? " << (intStack.isFull() ? "true" : "false") << endl;

    return 0;
}
