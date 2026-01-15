// SudokuGenerator.h

#ifndef SudokuGenerator_H
#define SudokuGenerator_H
#include<vector>
#include<iostream>
#include <cstdlib>
#include <ctime> 

class SudokuGenerator {
    private:
    std::vector<std::vector<int>> sudoku;
    public :
    std::vector<std::vector<int>> puzzleArr;

    SudokuGenerator();
    void printBoard(std::vector<std::vector<int>>& arr);
    std::vector<int> firstEmptyCell(std::vector<std::vector<int>>& arr);
    void setValue(int r,int c, int val);
    std::vector<int> shuffleArray(); 
    bool isValid(int r,int c, int value);
    bool solve(); 
    void generateBoard();
    void createPuzzle();
    const std::vector<std::vector<int>>& getSolution() const;
    const std::vector<std::vector<int>>& getPuzzle() const;

};

#endif