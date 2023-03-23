#pragma once 
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "AnimationWindow.h"
#include "Person.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

static constexpr int pad = 30;
static constexpr int btnW = 125;
static constexpr int btnH = 45;
static constexpr int fieldW = 200;
static constexpr int fieldH = 35;
static constexpr int fieldPad = 40;

// Values for Meetinwindow with w = 600 and h = 500 
static constexpr int quitBtnX = 450;
static constexpr int quitBtnY = 50;
static constexpr int personNewBtnX = 50;
static constexpr int personNewBtnY = 150;
static constexpr int personNameX = 50;
static constexpr int personNameY = 50;
static constexpr int personEmailX = 50;
static constexpr int personEmailY = 100;

class MeetingWindow : public TDT4102::AnimationWindow {
private:
    TDT4102::Button quitBtn;
    TDT4102::Button personNewBtn;
    TDT4102::TextInput personName;
    TDT4102::TextInput personEmail;
    std::vector<std::shared_ptr<Person>> people;
public:
    MeetingWindow(int x, int y, int w, int h, const std::string& title);
    void cb_quit();
    void cb_addPerson();
    void newPerson();
    void printPeople();
};
