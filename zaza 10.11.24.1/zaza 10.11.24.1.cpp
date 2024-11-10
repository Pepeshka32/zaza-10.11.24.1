#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class ForwardList {
private:
    Node* head;

public:
    ForwardList() : head(nullptr) {}

    void pushFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) return;
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    Node* getHead() const {
        return head;
    }

    ~ForwardList() {
        clear();
    }
};

int main() {
    ForwardList list;
    list.pushFront(10);
    list.append(20);
    list.pushFront(5);

    Node* node = list.getHead()->next;
    list.insertAfter(node, 15);

    list.clear();
    return 0;
}
