#include "Tetromino.h"
#include <map>
#include <cassert>

const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {
    {
        TetrominoType::T, {
            {0, 0, 0},
            {1, 1, 1},
            {0, 1, 0}
        }
    },
    {
        TetrominoType::J, {
            {0, 0, 0},
            {1, 1, 1},
            {0, 0, 1}
        }
    },
    {
        TetrominoType::I, {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        }
    },
    {
        TetrominoType::Z, {
            {0, 0, 0},
            {1, 1, 0},
            {0, 1, 1}
        }
    },
    {
        TetrominoType::L, {
            {1, 1, 1},
            {1, 0, 0},
            {0, 0, 0}
        }
    },
    {
        TetrominoType::S, {
            {0, 0, 0},
            {0, 1, 1},
            {1, 1, 0}
        }
    },
    {
        TetrominoType::O, {
            {1, 1},
            {1, 1}
        }
    }
};

const std::map<TetrominoType, TDT4102::Color> colorMap {
    {
        TetrominoType::T, TDT4102::Color::purple
    },
    {
        TetrominoType::J, TDT4102::Color::blue
    },
    {
        TetrominoType::I, TDT4102::Color::aqua
    },
    {
        TetrominoType::Z, TDT4102::Color::red
    },
    {
        TetrominoType::L, TDT4102::Color::orange
    },
    {
        TetrominoType::S, TDT4102::Color::lime
    },
    {
        TetrominoType::O, TDT4102::Color::yellow
    }
};

Tetromino::Tetromino() : matrixSize{0}, topLeftCorner{TDT4102::Point{0,0}}, color{TDT4102::Color::grey} {};

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : topLeftCorner{startingPoint} {
    std::vector<std::vector<int>> tetrominoVec = initialMatrixMap.at(tetType);
    matrixSize = tetrominoVec[0].size();
    
    blockMatrix.resize(matrixSize, std::vector<TetrominoType>(matrixSize, TetrominoType::NONE));
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            if (tetrominoVec[row][col] == 1) {
                blockMatrix[row][col] = tetType;
            }
        }
    }
    color = colorMap.at(tetType);
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

TDT4102::Point Tetromino::getPosition() {
    return topLeftCorner;
}

bool Tetromino::blockExist(int row, int col) {
    assert(row >= 0 && col >= 0);
    assert(row < matrixSize && col < matrixSize);
    return (blockMatrix[row][col] != TetrominoType::NONE);
}

TetrominoType Tetromino::getBlock(int row, int col) {
    assert(row >= 0 && col >= 0);
    assert(row < matrixSize && col < matrixSize);
    return blockMatrix[row][col];
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveLeft() {
    topLeftCorner.x -= blockSize;
}

void Tetromino::moveRight() {
    topLeftCorner.x += blockSize;
}

void Tetromino::moveDown() {
    topLeftCorner.y += blockSize;
}
