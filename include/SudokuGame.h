#ifndef SudokuGame_H
#define SudokuGame_H
#include<vector>
#include<iostream>
#include "SudokuGenerator.h"

class SudokuGame{
    private:
        SudokuGenerator generator;
        std::vector<std::vector<int>>solutionGrid;
    public:
        std::vector<std::vector<int>>playerGrid;
        SudokuGame();
        bool isComplete();
        void play();
};
#endif