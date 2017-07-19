all: Sudoku.o giveQuestion.cpp solve.cpp transform.cpp
	g++ -o giveQuestion giveQuestion.cpp Sudoku.o -std=c++0x
	g++ -o solve solve.cpp Sudoku.o -std=c++0x
	g++ -o transform transform.cpp Sudoku.cpp -std=c++0x
sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -std=c++0x
clean:
	rm *.o
