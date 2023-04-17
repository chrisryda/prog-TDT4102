#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>

enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

class Tetromino {
public:
    static constexpr int blockSize{30};
    Tetromino();
    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);

    int getMatrixSize();
    TDT4102::Point getPosition();
    
    bool blockExist(int row, int col);
    TetrominoType getBlock(int row, int col);
    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveLeft();
    void moveRight();
private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    TDT4102::Color color;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};
