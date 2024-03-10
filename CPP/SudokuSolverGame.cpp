
/*											<-:::------------[[TASK------03]]------------:::->
									---------------**---------------**-----------------**-----------------
													    	 Sudoku Solver
									---------------**---------------**-----------------**-----------------				
					Write a program that solves Sudoku puzzles. Implement an algorithm to solve puzzles of varying difficulty levels. */
				
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;

bool isSafe(char board[9][9], int row, int col, char num){
    for(int i=0; i<9; i++){
        if(board[i][col] == num) return false;
        if(board[row][i] == num) return false;
    }
    int startRow=row-row%3, startCol =col-col%3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i+startRow][j+startCol]==num)
                return false;
    return true;
}

bool solveSudoku(char board[9][9], int row, int col){
    if(row==9) return true;
    
    int nextRow, nextCol;
    if(col==8){
        nextRow=row+1;
        nextCol=0;
    } else{
        nextRow=row;
        nextCol=col+1;
    }
    
    if(board[row][col]!='.'){
        return solveSudoku(board, nextRow, nextCol);
    } else {
        for(char num='1'; num<='9'; num++){
            if(isSafe(board, row, col, num)){
                board[row][col] = num;
                if(solveSudoku(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
    }
    return false;
}

void printSudokuBoard(char board[9][9]) {
    cout<<"\n";
    for(int row = 0; row < 9; ++row){
        if(row%3==0){
            cout<<"\t\t\t\t\t+-------+-------+-------+\n";     
		}
        cout<<"\t\t\t\t\t";  // Added two more tabs
        for(int col=0; col<9; col++){
            if(col%3==0)
			cout << "| ";
            cout << (board[row][col] == '0' ? '.' : board[row][col]) << " ";
        }
        cout << "|\n";
    }
    cout << "\t\t\t\t\t+-------+-------+-------+\n";  
}

void Intro(){								// Intro function to display first_page of Introduction.
	
	cout<<"\t\t\t----***----\t----***----\t----***----\t----***----\t----***----\t----***----\t----***----";
	cout<<"\n\n\n\n\n\t\t\t\t\t      --{}{}{}---:::::::--{}{}{}--- SUDOKU SOLVER --{}{}{}---:::::::--{}{}{}--- "<<endl;
	cout<<"\t\t\t\t\t=========================================================================================="<<endl;
    cout<<"\t\t\t\t\t-----------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t->\t            WELCOME TO SUDOKU SOLVER PUZZLE                "<<endl;
    cout<<"\n\t\t\t\t\t->\t            MADE BY -> AHSAN ALI (ID == CA/CP/11906)                 "<<endl;
    cout<<"\n\t\t\t\t\t->\t             PRESENTED TO CODALPHA                                 "<<endl;
	cout<<"\t\t\t\t\t=========================================================================================="<<endl;
    cout<<"\t\t\t\t\t_________________________________________________________________________________________"<<endl;
    cout<<"Press any key to start the system......!";
	getch();
	system("cls");
    
}

int main(){
	system("color E0");	
	Intro();	
	char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout<<"\t\t\t\t\t  Initial Sudoku Board\n";  
    printSudokuBoard(board);

    if(solveSudoku(board, 0, 0)){
        cout<<"\n\t\t\t\t\t  Solved Sudoku Board\n";  
        printSudokuBoard(board);
    } else {
        cout<<"\nNo solution exists.\n";
    }
    return 0;
}

