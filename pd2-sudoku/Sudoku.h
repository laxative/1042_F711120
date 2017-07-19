using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		bool usedInRow(int,int);
		bool usedInCol(int,int);
		bool usedInBox(int,int,int);
		bool isSafe(int,int,int);
		int *findBlank();
		int backtracking();
		void solve();
		void changeNum(int,int);
		void changeRow(int,int);
		void changeCol(int,int);
		void rotate(int);
		void flip(int);
		void transform();
		void printOut(bool);
	private:
		int array[9][9];
		int ans[9][9];
};
