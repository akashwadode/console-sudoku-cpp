#include "SudokuGenerator.h"
using namespace std;

SudokuGenerator::SudokuGenerator(){
    sudoku.resize(9,vector<int>(9,0));
    puzzleArr.resize(9,vector<int>(9,0));
    generateBoard();
    // printBoard(sudoku);
    createPuzzle();
}

void SudokuGenerator::printBoard(vector<vector<int>>& arr){
    cout << "\n     0 1 2   3 4 5   6 7 8\n";
    cout << "   -------------------------\n";

    for(int i = 0; i < 9; i++){
        cout << i << " | ";     // row index
        for(int j = 0; j < 9; j++){
            if(arr[i][j] == 0)
                cout << ".";
            else
                cout << arr[i][j];
            cout << " ";
            if((j + 1) % 3 == 0) cout << "| ";
        }
        cout << "\n";

        if((i + 1) % 3 == 0)
            cout << "   -------------------------\n";
    }
}


vector<int> SudokuGenerator::shuffleArray(){
    vector<int> temp = {1,2,3,4,5,6,7,8,9};
    srand(time(0));
    for(int i=temp.size()-1;i>0;i--){
        int j = rand() % (i+1);
        swap(temp[i],temp[j]);
    }
    return temp;
}

vector<int> SudokuGenerator::firstEmptyCell(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                return {i,j};
            }
        }
    }
    return {-1,-1};
} 

bool SudokuGenerator::isValid(int r,int c, int value){
    //row check
    for(int i=0;i<r;i++){
        if(sudoku[i][c] == value) return false;
    }
    //column check
    for(int j=0;j<c;j++){
        if(sudoku[r][j] == value) return false;
    }
    //sub-grid check
    int rs = (r/3)*3; // row start
    int cs = (c/3)*3; // column start
    for(int i=rs;i<rs+3;i++){
        for(int j=cs;j<cs+3;j++){
            // if reach to position of value
            if(i==r && j==c){ 
                return true;
            }
            if(sudoku[i][j] == value){
                return false;
            }
        }
    }
    return true;
}

bool SudokuGenerator::solve(){
    vector<int> emptyCellIndex = firstEmptyCell(sudoku);
    int r = emptyCellIndex[0], c = emptyCellIndex[1];
    // sudoku complete
    if(r == -1) return true; 

    vector<int> nums = shuffleArray();
    for(int i : nums){
        if(isValid(r,c,i)){
            sudoku[r][c] = i;
            if(solve()){
                return true;
            }
            sudoku[r][c]=0;
        }
    } 
    return false;
}


void SudokuGenerator::generateBoard(){
    sudoku[0] = shuffleArray();
    // printBoard(sudoku);
    solve();
}

void SudokuGenerator::createPuzzle(){
    int count = 0;
    int r=0,c=0;
    srand(time(0));
    while(count < 46){
        r = rand() % 9;
        c = rand() % 9;
        if(puzzleArr[r][c] == 0){
            puzzleArr[r][c] = sudoku[r][c];
            count++;
        }
    }
    // printBoard(puzzleArr);

}

const vector<vector<int>>& SudokuGenerator::getSolution() const{
    return sudoku;
}
const vector<vector<int>>& SudokuGenerator::getPuzzle() const{
    return puzzleArr;
}