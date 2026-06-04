#pragma once
#include <iostream>
#include "Marsh.h"

using namespace std;

struct Node {

    Marsh data;
    Node* next;

    Node(const Marsh& m) {

        data = m;
        next = nullptr;
    }
};

class List {

private:

    Node* head;

public:

    List() {

        head = nullptr;
    }

    bool empty() {

        return head == nullptr;
    }

    void push_front(
        const Marsh& m) {

        Node* temp = new Node(m);

        temp->next = head;

        head = temp;
    }

    void push_back(
        const Marsh& m) {

        Node* temp = new Node(m);

        if (empty()) {

            head = temp;
            return;
        }

        Node* p = head;

        while (p->next != nullptr) {

            p = p->next;
        }

        p->next = temp;
    }

    Node* find(
        const char* name) {

        Node* p = head;

        while (p != nullptr) {

            if (
                strcmp(
                    p->data.name1,
                    name) == 0)

                return p;

            p = p->next;
        }

        return nullptr;
    }

    void remove(
        const char* name) {

        if (empty())
            return;

        if (
            strcmp(
                head->data.name1,
                name) == 0) {

            Node* temp = head;

            head = head->next;

            delete temp;

            return;
        }

        Node* p = head;

        while (
            p->next != nullptr &&
            strcmp(
                p->next->data.name1,
                name) != 0) {

            p = p->next;
        }

        if (p->next != nullptr) {

            Node* temp = p->next;

            p->next = temp->next;

            delete temp;
        }
    }

    void insert_sorted(
        const Marsh& m) {

        Node* temp = new Node(m);

        if (
            empty() ||
            m.number <
            head->data.number) {

            temp->next = head;

            head = temp;

            return;
        }

        Node* p = head;

        while (
            p->next != nullptr &&
            p->next->data.number
            < m.number) {

            p = p->next;
        }

        temp->next = p->next;

        p->next = temp;
    }

    friend ostream& operator<<(
        ostream& os,
        const List& lst);

    ~List() {

        while (head != nullptr) {

            Node* temp = head;

            head = head->next;

            delete temp;
        }
    }
};

ostream& operator<<(
    ostream& os,
    const List& lst) {

    Node* p = lst.head;

    while (p != nullptr) {

        os << p->data << endl;

        p = p->next;
    }

    return os;
}
