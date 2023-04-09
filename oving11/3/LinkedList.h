#pragma once

#include <memory>
#include <string>
#include <ostream>
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
            os << "Next: " << node.getNext()->getValue() << std::endl;
        }
        else if (node.getNext() == nullptr) {
            os << "*Node*" << std::endl;
            os << "Value: " << node.getValue() << std::endl;
            os << "Next: " << node.getNext() << std::endl;
            os << "Prev: " << node.getPrev()->getValue() << std::endl;

            os << "\n--Tail--";
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
    ~LinkedList() = default;

    bool isEmpty() const { return head->next == nullptr; }
    Node<T>* begin() const { return head.get(); }
    Node<T>* end() const { return tail; }

    Node<T>* insert(Node<T> *pos, const T value) {
        std::unique_ptr<Node<T>> newNode;
    
        if (pos == head.get() && !isEmpty()) {
            std::cerr << "Terminating: Cannot add node before head" << std::endl;
            throw new std::invalid_argument("Cannot add node before head");
        } else if (isEmpty()) {
            newNode = std::make_unique<Node<T>>(value, nullptr, head.get());
            Node<T>* ret = newNode.get();

            head->next = std::move(newNode);
            return ret;
        } else {
            newNode = std::make_unique<Node<T>>(value, nullptr, nullptr);
            Node<T>* ret = newNode.get();
            
            newNode->prev = pos->prev;
            newNode->next = std::move(pos->prev->next);
            pos->prev = newNode.get();
            newNode->prev->next = std::move(newNode);
            return ret;
        }
        return newNode.get();
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
        if (pos == head.get()) {
            std::cerr << "Terminating: Cannot remove head/tail" << std::endl;
            throw new std::invalid_argument("Cannot remove head/tail");
        } else {
            Node<T>* ret = pos->getNext(); 
            pos->next->prev = pos->prev;
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
