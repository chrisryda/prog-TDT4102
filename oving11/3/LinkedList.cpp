#include "LinkedList.h"

LinkedList::Node* LinkedList::LinkedList::insert(Node *pos, const std::string& value) {
    std::unique_ptr<Node> newNode;
    
    if (pos == head.get() && !isEmpty()) {
        std::cerr << "Terminating: Cannot add node before head" << std::endl;
        throw new std::invalid_argument("Cannot add node before head");
    } else if (isEmpty()) {
        newNode = std::make_unique<Node>(value, nullptr, head.get());
        Node* ret = newNode.get();

        head->next = std::move(newNode);
        return ret;
    } else {
        newNode = std::make_unique<Node>(value, nullptr, nullptr);
        Node* ret = newNode.get();
        
        newNode->prev = pos->prev;
        newNode->next = std::move(pos->prev->next);
        pos->prev = newNode.get();
        newNode->prev->next = std::move(newNode);
        return ret;
    }
    return newNode.get();
}

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value) {
    Node* n = head.get();
    while (n != nullptr) {
        if ((n->getValue()) == value) {
            return n;
        }
        n = n->getNext();
    }
    return tail->getNext();
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos) {
    if (pos == head.get()) {
        std::cerr << "Terminating: Cannot remove head/tail" << std::endl;
        throw new std::invalid_argument("Cannot remove head/tail");
    } else {
        Node* ret = pos->getNext(); 
        pos->next->prev = pos->prev;
        pos->prev->next = std::move(pos->next);
        return ret;
    }
}

void LinkedList::LinkedList::remove(const std::string& value) {
    Node* n = head.get();
    while (n != nullptr) {
        if (n->getValue() == value) {
            remove(n);
        }
        n = n->getNext();
    }
}

void testLinkedList() {
    LinkedList::LinkedList list;
    LinkedList::Node* first = list.insert(list.end(), "first");
    LinkedList::Node* second = list.insert(first, "second");
    list.insert(second, "third");
    
    LinkedList::Node* secondFound = list.find("second");
    LinkedList::Node* found = list.insert(secondFound, "found");

    std::cout << list << std::endl;
    list.remove(found);
    std::cout << list << std::endl;
}
