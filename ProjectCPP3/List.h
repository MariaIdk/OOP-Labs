#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    T Pop() {
        if (!head)
            throw QueueEmptyErr();

        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;

        return data;
    }
};

#endif /* _LIST_H_ */
