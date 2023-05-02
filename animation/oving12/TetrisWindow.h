#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

class TetrisWindow : public AnimationWindow {
public:
    TetrisWindow();
    void run();

private:
    static constexpr int tetrisGridHeight {18};
    static constexpr int tetrisGridWidth {10};
    static constexpr int startRow {1};
    static constexpr int startColumn {tetrisGridWidth/2-1};

    static constexpr int blockSize {Tetromino::blockSize};
    static constexpr Point startPoint {startColumn, startRow};
    static constexpr int sideBarLength = 180;
    static constexpr int sideBarHeight = 50;
    static constexpr int outBoxOffset = 70;

    Tetromino currentTetromino;
    vector<vector<TetrominoType>> gridMatrix;
    
    int score{0};
    bool playing {true};
    bool paused {false};

    void generateRandomTetromino();
    void moveTetrominoDown();
    void fastenTetromino();

    bool tetrominoCrashesAt(Point location);
    bool hasCrashed();

    void handleInput();
    void drawGridMatrix();
    void drawCurrentTetromino();

    void removeFullRows(); 

    TextInput scoreBox;
    TextInput highScoreBox;
    
    Button quitBtn;
    Button restartBtn;
    Button pauseBtn;

    void cb_quit() {this->lostGame();}
    void cb_restart() {this->restartGame();}
    void cb_pause() {this->pauseGame();}

    void lostGame();
    void restartGame();
    void pauseGame();    
};
