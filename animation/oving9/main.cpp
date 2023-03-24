#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <memory>

using namespace std;

int main() {
    MeetingWindow mw{50, 50, 600, 700, "MeetingWindow"};
    mw.wait_for_close();
    return 0;
}
