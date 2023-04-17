#include "Tetromino.h"
#include <map>
#include <iostream>

const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {
    {
        TetrominoType::J, {
            {0, 0, 0},
            {1, 1, 1},
            {0, 0, 1}
        }
    }
};

Tetromino::Tetromino() : topLeftCorner{TDT4102::Point{0,0}}, matrixSize{0} {};

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
    // std::cout << matrixSize << std::endl;
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
