#include "LinkedList.h"
#include <string>

void testLinkedListOverflow() {
    std::cout << "Testing LinkedList destructor overflow\n";
    using LinkedList::LinkedList;
    constexpr unsigned int N = 1'000'000;
    {
        LinkedList<std::string> list;
        for (unsigned int i = 0; i < N; ++i) {
            list.insert(list.end(), std::to_string(i));
        }
        std::cout << "All elements added\n";
    } // Destruktøren kjører
    std::cout << "List destructed\n";
}

int main() {
    testLinkedList();
    testLinkedListOverflow();
    return 0;
}
