//
//  sudoku.hpp
//  project 1 redo
//
//  Created by Ameya Pednekar
//  Copyright (c) 2013 Ameya Pednekar. All rights reserved.
//

#ifndef project_1_redo_sudoku_hpp
#define project_1_redo_sudoku_hpp

#include <cstdlib>

using namespace std;

class sudoku {
    private :

    int board [9][9];
    bool num_check(int row, int col, int num);

    public :

    sudoku ();
    void display();
    void make_board();
    bool get_num(int,int);

};




sudoku :: sudoku() {

    srand(time(NULL));

    for(int i=0;i< 9; i++) {
        for(int j=0;j<9;j++) {
            board[i][j]=0;
        }
    }


}

bool sudoku :: num_check (int row, int col, int num) { // checks if number is ok for 3X3 and 9X9

    for( int i=0; i< 9; i++) { // 9X9 checker

        if (board[row][i]==num)
            return false;
        if (board[i][col]==num)
            return false;

    }

    int row_locate=row-(row%3);
    int col_locate=col-(col%3);

    for(int i=row_locate;i<row_locate+3;i++) { // 3X3 checker
        for (int j=col_locate; j< col_locate+3; j++) {
            if(board[i][j]==num)
                return false;
        }
    }

    return true;
}


bool sudoku :: get_num(int r,int c) {


    if(r==0 && c==9)
        return true;// the board is done

    int random_number = (rand() % 9 + 1); //generates a random number between 1-9

    if( num_check(r,c,random_number)){
        board[r][c]=random_number;
        if ((get_num((r+1)%9, (r+1)%9==0?c+1:c) )){
            return true;
        } else{
            board[r][c]=0;
        }
    }


    for(int i=(random_number%9 +1); i != random_number; i=(i%9 +1))
    {


        if( num_check(r,c,i)){
            board[r][c]=i;
            if ((get_num((r+1)%9, (r+1)%9==0?c+1:c) )){
                return true;
            } else{
                board[r][c]=0;
            }
        }

    }

   return false; // got no number for this

}

void sudoku :: make_board() {
    int r=0, c=0;

    get_num(r, c);

   }




void sudoku ::display() {

    for(int x = 0;x<9;x++){
		cout << ((x%3 == 0)?" =======================\n| ":"| ");
		for(int y = 0; y<9; y++){
			cout << board[x][y] << " ";
			cout << ((y%3 == 2)?"| ":"");
		}
		cout <<  endl;
	}
	cout << " =======================" << endl;
}

#endif
