#include"Sudoku.h"
#include<cstring>
#include<cstdlib>
#include<new>
#include<ctime>
#include<cstdio>
#include<iostream>
using namespace std;
int count=0;
void Sudoku::giveQuestion() {
	int arr[9][9] = {
		{0,0,0,0,5,0,0,9,0},
		{4,0,0,0,0,0,0,0,2},
		{0,0,6,7,0,0,0,0,0},
		{2,0,0,0,0,0,0,0,0},
		{9,5,0,0,0,0,0,1,0},
		{0,0,0,6,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,3},
		{0,8,0,0,0,0,7,0,6},
		{0,0,0,0,1,3,0,0,0},
	};
	memcpy(array[0],arr[0],81*sizeof(int));
	transform();
}
void Sudoku::readIn() {
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			cin >> array[i][j];
		}
	}
}
int* Sudoku::findBlank(){
	int* blank = new int[2];
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(array[i][j] == 0) {
				blank[0] = i;
				blank[1] = j;
				return blank;
			}
		}
	}
	blank[0] = -1;
	blank[1] = -1;
	return blank;
}
bool Sudoku::usedInRow(int row, int num) {
	for(int i=0;i<9;i++) {
		if(array[row][i] == num)  return true;
	}
	return false;
}
bool Sudoku::usedInCol(int col, int num) {
	for(int i=0;i<9;i++) {
		if(array[i][col] == num)  return true;
	}
	return false;
}
bool Sudoku::usedInBox(int row, int col, int num) {
	for(int i=3*(row/3);i<3*(row/3)+3;i++) {
		for(int j=3*(col/3);j<3*(col/3)+3;j++) {
			if(array[i][j] == num)  return true;
		}
	}
	return false;
}
bool Sudoku::isSafe(int row, int col, int num) {
	if(!usedInRow(row,num) && !usedInCol(col,num) && !usedInBox(row,col,num)) return true;
	return false;
}
void Sudoku::solve() {
	int temp;
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(array[i][j]>9 || array[i][j]<0) {
				cout << 0 << endl;
				return;
			}
		}
	}
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(array[i][j] != 0) {
				temp = array[i][j];
				array[i][j] = 0;
				if(!isSafe(i,j,temp)) {
					cout << 0 << endl;
					return;
				}
				else {
					array[i][j] = temp;
					continue;
				}
			}
		}
	}
	backtracking();
	int ans = count;
	if(ans==1) {
		cout << 1 << endl;
		printOut(true);
	}
	else if(ans>1)  cout << 2 << endl;
	else cout << 0 << endl;
}
int Sudoku::backtracking() {
	if(count>1) return 2;
	int row,col;
	int *Blank = findBlank();
	row = Blank[0];
	col = Blank[1];
	if(row < 0)  {
		memcpy(ans[0],array[0],81*sizeof(int));
		count++;
		return 0;
	}
	for(int i=1;i<=9;i++) {
		if(isSafe(row,col,i)) {
			array[row][col] = i;
			backtracking();
			array[row][col] = 0;
		}
	}
	if(count>1) return 2;
	else if(count==1) return 1;
	else return 0;
}
void Sudoku::changeNum(int a, int b) {
	if((a<0 || a>9) || (b<0 || b>9)) {
		cout << "Error : changeNum" << endl;
		exit(1);
	}
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(array[i][j] == a)  array[i][j] = b;
			else if(array[i][j] == b)  array[i][j] = a;
		}
	}
}
void Sudoku::changeRow(int a, int b) {
	if((a<0 || a>2) || (b<0 || b>2)) {
		cout << "Error : changeNum" << endl;
		exit(1);
	}
	int temparr[3][9];
	for(int i=a*3;i<a*3+3;i++)  memcpy(temparr[i-a*3],array[i],9*sizeof(int));
	for(int i=a*3;i<a*3+3;i++)  memcpy(array[i],array[i-a*3+b*3],9*sizeof(int));
	for(int i=b*3;i<b*3+3;i++)  memcpy(array[i],temparr[i-b*3],9*sizeof(int));
}
void Sudoku::changeCol(int a, int b) {
	if((a<0 || a>2) || (b<0 || b>2)) {
		cout << "Error : changeCol" << endl;
		exit(1);
	}
	int temparr[9][3];
	for(int i=0;i<9;i++)  memcpy(temparr[i],array[i]+a*3,3*sizeof(int));
	for(int i=0;i<9;i++)  memcpy(array[i]+a*3,array[i]+b*3,3*sizeof(int));
	for(int i=0;i<9;i++)  memcpy(array[i]+b*3,temparr[i],3*sizeof(int));
}
void Sudoku::rotate(int n) {
	if(n<0 || n>100) {
		cout << "Error : rotate" << endl;
		exit(1);
	}
	int temparray[9][9];
	while(n%4!=0) {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				temparray[j][8-i] = array[i][j];
			}
		}
		for(int i=0;i<9;i++) memcpy(array[i],temparray[i],9*sizeof(int));
		n--;
	}
}
void Sudoku::flip(int n) {
	int temparray[9][9];
	switch(n) {
		case 0:
			memcpy(temparray[0],array[0],81*sizeof(int));
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++)
					array[i][j] = temparray[i][8-j];
			}
			break;
		case 1:
			memcpy(temparray[0],array[0],81*sizeof(int));
			for(int i=0;i<9;i++)  memcpy(array[i],temparray[8-i],9*sizeof(int));
			break;
		default:
			cout << "Error : flip" << endl;
			exit(1);
	}
}
void Sudoku::transform() {
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	printOut(false);
}
void Sudoku::printOut(bool isAns) {
	if(isAns) {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cout << ans[i][j];
				if(j!=8) cout << " ";
			}
			cout << endl;
		}
	}
	else {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cout << array[i][j];
				if(j!=8) cout << " ";
			}
			cout << endl;
		}
	}
}
