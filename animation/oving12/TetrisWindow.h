#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

class TetrisWindow : public TDT4102::AnimationWindow {
public:
    TetrisWindow();
    void run();
private:
    void handleInput();
};
