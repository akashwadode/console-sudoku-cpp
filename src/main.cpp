#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<vector>
#include "SudokuGenerator.h"
#include "SudokuGame.h"
using namespace std;



int main(){
    SudokuGenerator s1;    
    cout << "Welcome to My Sudoku" << endl;
    int n;
    cout << "1. Start game\n2. Quit game\n>> ";
    cin >> n;
    if(n==1){
        SudokuGame g1;
        g1.play();
    }
}