#include "LinkedList.h"

void testLinkedList() {
    LinkedList::LinkedList<std::string> list;
    LinkedList::Node<std::string>* first = list.insert(list.end(), "first");
    LinkedList::Node<std::string>* second = list.insert(first, "second");
    list.insert(second, "third");
    
    LinkedList::Node<std::string>* secondFound = list.find("second");
    LinkedList::Node<std::string>* found = list.insert(secondFound, "found");

    std::cout << list << std::endl;
    list.remove(found);
    std::cout << list << std::endl;
}
