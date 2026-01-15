APP = sudoku

SRC = src/main.cpp \
      src/SudokuGenerator.cpp \
      src/SudokuGame.cpp

INCLUDE = -Iinclude

$(APP): $(SRC)
	g++ -std=c++17 $(SRC) $(INCLUDE) -o $(APP)

run: $(APP)
	./$(APP)

clean:
	del $(APP).exe
