#include "TetrisWindow.h"
#include <iostream>

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Kall moveTetrominoDown() her
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        /********************************************************/

        next_frame();
    }
}

void TetrisWindow::handleInput() {
    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    
    if(currentZKeyState && !lastZKeyState) {
        std::cout << "Hello from z\n";
    }

    if(currentUpKeyState && !lastUpKeyState) {
        std::cout << "Hello from up\n";
    }

    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}
