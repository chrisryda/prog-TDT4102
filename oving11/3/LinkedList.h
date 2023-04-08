#pragma once

#include <memory>
#include <string>
#include <ostream>
#include <iostream>

void testLinkedList();

namespace LinkedList {
class Node {
private:
    const std::string value;
    std::unique_ptr<Node> next;
    Node* prev;

public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    Node(const std::string& value, std::unique_ptr<Node> next, Node* prev) : value(value), next(std::move(next)), prev(prev) {}
    ~Node() = default;

    std::string getValue() const { return value; }
    Node* getNext() const { return next.get(); }
    Node* getPrev() const { return prev; }

    friend class LinkedList;
    friend std::ostream & operator<<(std::ostream & os, const Node & node) {
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
};

class LinkedList {
private:
    std::unique_ptr<Node> head;
    Node* const tail;
public:
    LinkedList() : head(std::make_unique<Node>("head", nullptr, nullptr)), tail(head.get()) {}
    ~LinkedList() = default;

    bool isEmpty() const { return head->next == nullptr; }
    Node* begin() const { return head.get(); }
    Node* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos. Returns a pointer to the new Node
    Node* insert(Node *pos, const std::string& value);

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node* find(const std::string& value);

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node* remove(Node* pos);

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const std::string& value);

    // write a string representation of the list to the ostream
    //-------------------// TODO: Fix print function-------------------
    friend std::ostream & operator<<(std::ostream & os, const LinkedList& list) {
        if (list.isEmpty()) {
            os << "List is empty" << std::endl;
            return os;
        }
        Node* n = list.begin();
        while (n->getNext() != nullptr) {
            os << *n << std::endl;
            n = n->getNext();
        }
        os << *n << std::endl;
        return os;
    }
};
}
