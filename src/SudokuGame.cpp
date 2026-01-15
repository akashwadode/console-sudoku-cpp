#include "SudokuGame.h"
#include "SudokuGenerator.h"
using namespace std;

SudokuGame::SudokuGame() {
    generator = SudokuGenerator();

    solutionGrid = generator.getSolution();
    playerGrid   = generator.getPuzzle();

}

bool SudokuGame::isComplete() {
    for (auto &row : playerGrid)
        for (int v : row)
            if (v == 0) return false;

    return true;
}
void printDivider() {
    cout << "\n----------------------------------------\n";
}

void SudokuGame::play(){

    while(!isComplete()){
        cout << endl;
        printDivider();
        cout << "        S U D O K U";
        printDivider();
        generator.printBoard(playerGrid);
        printDivider();

        cout << "1. Enter value\n2. Exit\n>>";
        int option;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Enter number only.\n";
            continue;
        }

        if(option == 1){
            int r, c, val;
            cout << "row - col - value => ";
            cin >> r >> c >> val;
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Use numbers only.\n";
                continue;
            }
            
            if (r < 0 || r > 8 || c < 0 || c > 8 || val < 1 || val > 9) {
                cout << "Invalid move.Try Again.\n";
                continue;
            }
            if (playerGrid[r][c] != 0) {
                // cannot overwrite
                cout << "Cell already filled.\n";
                continue;
            }

            if (solutionGrid[r][c] != val) {
                // wrong  answer
                cout << "Incorrect value!\n";
                cout << "Press Enter to try again...";
                cin.ignore();
                cin.get();
            } else {
                // correct answer
                playerGrid[r][c] = val;
                cout << "Nice! Correct move.\n";
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
            }

        }else if (option == 2){
            cout << "Exit? (y/n): ";
            char ch;
            cin >> ch;
            if (ch == 'y')
                return;   
        } 
        else{
            cout << "Invalid choice!\n";
        }
        printDivider();
    }

    if(isComplete())
        cout << "You solved it!\n";
}
