#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <memory>
#include "Node.h"

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int size;

public:
    DoublyLinkedList() : head(0), tail(0), size(0) {}

    void push_front(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(T value) {
        auto newNode = std::make_shared<Node<T>>(value);

        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) throw std::runtime_error("Empty");

        head = head->next;
        if (head) head->prev = 0;
        else tail = 0;

        size--;
    }

    void pop_back() {
        if (!tail) throw std::runtime_error("Empty");

        tail = tail->prev;
        if (tail) tail->next = 0;
        else head = 0;

        size--;
    }

    void print() {
        auto temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

#endif