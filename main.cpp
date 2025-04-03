#include <iostream>
#include <cmath>

struct Node {
    int value;
    Node *next;
    Node(int value): value(value), next(nullptr) {};
};

class Stack{
    Node* head = nullptr;

    public:

        void push(int x) {
            Node* newNode = new Node(x);
            newNode -> next = head;
            head = newNode;
        }

        int pop() {
            if(isEmpty()) {
                std::cout << "THERE'S NO HEAD" << std::endl;
                return;
            }
            Node* temp = head;
            int value = head -> value;
            head = head -> next;
            delete temp;
            return value;
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void clean() {
            while(!isEmpty()) {
                pop();
            }
        }
};

class Queue{
    Stack inStack;
    Stack outStack;

    public:

        void fromInToOut() {
            while(!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }

        void enqueue(int value) {
            inStack.push(value);
        }

        int dequeue(int value) {
            if(isEmpty()) {
                std::cout << "ES GIBT(THERE'S) NOTHING IN QUEUE" << std::endl;
                return;
            }
            if(outStack.isEmpty()) {
                fromInToOut();
            }
            return outStack.pop();
        }

        bool isEmpty() {
            return inStack.isEmpty() && outStack.isEmpty();
        }
};

int main() {


    return 0;
}