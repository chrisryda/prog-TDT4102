#pragma once
#include "Point.h"
#include <vector>

enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

class Tetromino {
public:
    static constexpr int blockSize {30};

    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    
    void rotateClockwise();
    void rotateCounterClockwise();
private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};
