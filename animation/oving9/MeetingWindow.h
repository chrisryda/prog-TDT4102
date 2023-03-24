#pragma once 
#include "widgets/TextInput.h"
#include "widgets/DropdownList.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Person.h"
#include "Meeting.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

static constexpr int pad = 30;
static constexpr int btnW = 150;
static constexpr int btnH = 45;
static constexpr int fieldW = 200;
static constexpr int fieldH = 35;
static constexpr int fieldPad = 40;

// Values for MeetingWindow with w = 600 and h = 500 
static constexpr int quitBtnX = 460;
static constexpr int quitBtnY = 10;

static constexpr int leftSideMeetingFieldsX = 10;
static constexpr int leftSidePersonFieldsX = 250;
static constexpr int leftFieldOneY = 10;
static constexpr int leftFieldTwoY = 60;
static constexpr int leftFieldThreeY = 110;
static constexpr int leftFieldFourY = 160;
static constexpr int leftFieldFiveY = 210;
static constexpr int leftFieldSixY = 260;
static constexpr int leftFieldSevenY = 310;

static constexpr int personDataX = 300;
static constexpr int personDataY = 400;
static constexpr int meetingDataX = 10;

class MeetingWindow : public TDT4102::AnimationWindow {
private:
    TDT4102::Button quitBtn;
    TDT4102::Button createMeetingBtn;
    TDT4102::Button createPersonBtn;

    TDT4102::TextInput personName;
    TDT4102::TextInput personEmail;
    TDT4102::TextInput personSeats;
    TDT4102::TextInput personData;
    TDT4102::Button personNewBtn;

    TDT4102::Button meetingNewBtn;
    TDT4102::TextInput meetingSubject;
    TDT4102::TextInput meetingDay;
    TDT4102::TextInput meetingStart;
    TDT4102::TextInput meetingEnd;
    TDT4102::DropdownList meetingLocation;
    TDT4102::DropdownList meetingLeader;
    TDT4102::TextInput meetingData;

    std::vector<std::shared_ptr<Person>> people;
    std::vector<std::unique_ptr<Meeting>> meetings;
    
public:
    MeetingWindow(int x, int y, int w, int h, const std::string& title);
    void cb_quit();
    void cb_addPerson();
    void cb_addMeeting();
    void cb_persons();
    void cb_meetings();
    void showPersonPage();
    void showMeetingPage();
    void newPerson();
    void updatePeopleDisplay();
    void newMeeting();
    void updateMeetingDisplay();
};
