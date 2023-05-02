#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>

enum class TetrominoType{J, L, T, S, Z, O, I, NONE};
using namespace TDT4102;
using namespace std;
class Tetromino {
public:
    static constexpr int blockSize{30};
    Tetromino();
    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);

    int getMatrixSize() const;
    TDT4102::Point getPosition() const;
    std::vector<std::vector<TetrominoType>> getBlockMatrix() const;
    
    bool blockExist(int row, int col) const;
    TetrominoType getBlock(int row, int col) const;
    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveLeft();
    void moveRight();
private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};
