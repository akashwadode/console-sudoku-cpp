# Console Sudoku Game (C++)

A fully functional console-based Sudoku game built in C++ using
backtracking, object-oriented design, and clean modular architecture.

---

## Features
- Generates a valid 9×9 Sudoku board using backtracking
- Creates playable puzzles by removing cells
- Interactive console gameplay
- Input validation and real-time feedback
- Clean board rendering with row & column indices
- Cross-platform build using Makefile

---

## Project Structure
- `SudokuGenerator`  
  Responsible for generating a valid Sudoku board using backtracking.

- `SudokuGame`  
  Handles gameplay logic, user input, validation, and UI rendering.

---

## How Sudoku Generation Works
1. Generate a complete valid Sudoku using backtracking
2. Copy the solved board
3. Remove numbers to create a playable puzzle
4. Store the solved board separately for validation

---

## How to Run

```bash
mingw32-make
mingw32-make run
