#pragma once

#include <memory>
#include <string>
#include <ostream>
#include <cassert>
#include <iostream>

void testLinkedList();

namespace LinkedList {

template <typename T>
class LinkedList;

template <typename T>
class Node {
private:
    const T value;
    std::unique_ptr<Node<T>> next;
    Node<T>* prev;

public:
    Node(const T value, std::unique_ptr<Node<T>> next, Node<T>* prev) : value(value), next(std::move(next)), prev(prev) {}
    Node() : value(), next(nullptr), prev(nullptr) {}
    ~Node() = default;

    T getValue() const { return value; }
    Node<T>* getNext() const { return next.get(); }
    Node<T>* getPrev() const { return prev; }

    friend std::ostream & operator<<(std::ostream & os, const Node<T> & node) {
        if (node.getPrev() == nullptr) {
            os << "\n--Head--" << std::endl;
            os << "Value: " << node.getValue() << std::endl;
            os << "Next: " << node.getNext()->getValue() << std::endl;
        }
        else if (node.getNext() == nullptr) {
            os << "--Tail--" << std::endl;
            os << "Next: " << node.getNext() << std::endl;
            os << "Prev: " << node.getPrev()->getValue() << std::endl;

        } else {
            os << "*Node*" << std::endl;
            os << "Value: " << node.getValue() << std::endl;
            os << "Next: " << node.getNext()->getValue() << std::endl;
            os << "Prev: " << node.getPrev()->getValue() << std::endl;
        }
        
        return os;
    }
    
    friend class LinkedList<T>;
};

template <typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* const tail;
public:
    LinkedList() : head(std::make_unique<Node<T>>()), tail(head.get()) {}
    ~LinkedList() {
        Node<T>* current = head.get();
        while (current->getNext()) {
            std::cout << "Deleting " << current->getValue() << std::endl;
            current = remove(current);
        }
    }

    bool isEmpty() const { return head->next == nullptr; }
    Node<T>* begin() const { return head.get(); }
    Node<T>* end() const { return tail; }

    Node<T>* insert(Node<T> *pos, const T value) {
        assert(pos != nullptr);
        if (pos == head.get()) {
            head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
            pos->prev = head.get();
        } else {
           Node<T>* prevNode = pos->getPrev();
           std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value, std::move(prevNode->next), prevNode);
           pos->prev = newNode.get();
           prevNode->next = std::move(newNode);
        }
        return pos->getPrev();
    }

    Node<T>* find(const T value) {
        Node<T>* n = head.get();
        while (n != nullptr) {
            if ((n->getValue()) == value) {
                return n;
            }
            n = n->getNext();
        }
        return tail->getNext();
    }

    Node<T>* remove(Node<T>* pos) {
        if (pos == begin()) {
            Node<T>* ret = pos->getNext(); 
            head = std::move(pos->next);
            head->prev = nullptr;
            return ret;
        } else {
            Node<T>* ret = pos->getNext(); 
            pos->next->prev = pos->getPrev();
            pos->prev->next = std::move(pos->next);
            return ret;
        }
    }

    void remove(const T value) {
        Node<T>* n = head.get();
        while (n != nullptr) {
            if (n->getValue() == value) {
                remove(n);
            }
            n = n->getNext();
        }
    }

    friend std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list) {
        if (list.isEmpty()) {
            os << "List is empty" << std::endl;
            return os;
        }
        Node<T>* n = list.begin();
        while (n->getNext() != nullptr) {
            os << *n << std::endl;
            n = n->getNext();
        }
        os << *n << std::endl;
        return os;
    }
};

}
