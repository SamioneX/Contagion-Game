#include <iostream>
#include <cstdio>
#include <cstdlib>   // for exit() and abs()
using namespace std;

// The 25 board position variables may be global variables, but no other variables may be global.
char  p1, p2, p3, p4, p5,
      p6, p7, p8, p9,p10,
     p11,p12,p13,p14,p15,
     p16,p17,p18,p19,p20,
     p21,p22,p23,p24,p25;


//-----------------------------------------------------------------------------------------
// Display the game instructions
void displayInstructions()
{
    cout << " \n"
         << "Welcome to the 2-player game of Contagion, where the point of the game is    \n"
         << "to capture as much of the board as possible.  On each move you must enter \n"
         << "the row and column position of one of your current pieces (e.g. a1) and   \n"
         << "the row and column of an empty destination, which must be one or two      \n"
         << "squares away.  Moves can be made horizontally, vertically, or diagonally. \n"
         << " \n"
         << "If the destination is one square away, then an additional piece for you   \n"
         << "is placed in the destination square.  If the destination is two squares   \n"
         << "away (a jump move), then the original piece is moved to that destination. \n"
         << "jumping over a single square or any player's piece.                       \n"
         << " \n"
         << "After a piece has been moved, all opponent pieces adjacent to the         \n"
         << "destination are changed to match the piece of the user making the move.   \n"
         << "Player X moves first.     \n"
         << " \n"
         << "A valid first move, for instance, could be: a1 a2  which since it is just \n"
         << "one square away, would put an additional X on square a2.  Alternatively   \n"
         << "if the first move is:  a1 c3  then since it is two squares away, the piece\n"
         << "currently at a1 would be moved to destination c3.                         \n"
         << endl;
}


//-----------------------------------------------------------------------------------------
// Display the board, using the global board variables
// For reference here are the board row, col and board variable values:
//       1  2  3  4  5
//    ----------------
//  A |  1  2  3  4  5
//  B |  6  7  8  9 10
//  C | 11 12 13 14 15
//  D | 16 17 18 19 20
//  E | 21 22 23 24 25
//
void displayBoard()
{
    cout << "    1   2   3   4   5  \n"
         << "  ---------------------\n"
         << "A | " <<  p1 << " | " <<  p2 << " | " <<  p3 << " | " <<  p4 << " | " <<  p5 << " | A \n"
         << "  |---|---|---|---|---| \n"
         << "B | " <<  p6 << " | " <<  p7 << " | " <<  p8 << " | " <<  p9 << " | " << p10 << " | B \n"
         << "  |---|---|---|---|---| \n"
         << "C | " << p11 << " | " << p12 << " | " << p13 << " | " << p14 << " | " << p15 << " | C \n"
         << "  |---|---|---|---|---| \n"
         << "D | " << p16 << " | " << p17 << " | " << p18 << " | " << p19 << " | " << p20 << " | D \n"
         << "  |---|---|---|---|---| \n"
         << "E | " << p21 << " | " << p22 << " | " << p23 << " | " << p24 << " | " << p25 << " | E \n"
         << "  ---------------------\n"
         << "    1   2   3   4   5  \n"
         << endl;
}
// Get the value at a board position
char getValue(char row, int col) {
  char boardValue;
  if ((row == 'A') && (col == 1)) {
    boardValue = p1;
  }
  else if ((row == 'A') && (col == 2)) {
    boardValue = p2;
  }
  else if ((row == 'A') && (col == 3)) {
    boardValue = p3;
  }
  else if ((row == 'A') && (col == 4)) {
    boardValue = p4;
  }
  else if ((row == 'A') && (col == 5)) {
    boardValue = p5;
  }
  else if ((row == 'B') && (col == 1)) {
    boardValue = p6;
  }
  else if ((row == 'B') && (col == 2)) {
    boardValue = p7;
  }
  else if ((row == 'B') && (col == 3)) {
    boardValue = p8;
  }
  else if ((row == 'B') && (col == 4)) {
    boardValue = p9;
  }
  else if ((row == 'B') && (col == 5)) {
    boardValue = p10;
  }
  else if ((row == 'C') && (col == 1)) {
    boardValue = p11;
  }
  else if ((row == 'C') && (col == 2)) {
    boardValue = p12;
  }
  else if ((row == 'C') && (col == 3)) {
    boardValue = p13;
  }
  else if ((row == 'C') && (col == 4)) {
    boardValue = p14;
  }
  else if ((row == 'C') && (col == 5)) {
    boardValue = p15;
  }
  else if ((row == 'D') && (col == 1)) {
    boardValue = p16;
  }
  else if ((row == 'D') && (col == 2)) {
    boardValue = p17;
  }
  else if ((row == 'D') && (col == 3)) {
    boardValue = p18;
  }
  else if ((row == 'D') && (col == 4)) {
    boardValue = p19;
  }
  else if ((row == 'D') && (col == 5)) {
    boardValue = p20;
  }
  else if ((row == 'E') && (col == 1)) {
    boardValue = p21;
  }
  else if ((row == 'E') && (col == 2)) {
    boardValue = p22;
  }
  else if ((row == 'E') && (col == 3)) {
    boardValue = p23;
  }
  else if ((row == 'E') && (col == 4)) {
    boardValue = p24;
  }
  else if ((row == 'E') && (col == 5)) {
    boardValue = p25;
  }
  else {
    boardValue = '~';
  }
  return boardValue;
}
// Set the value at a board position
void setValue(char row, int col, char value) {
  if ((row == 'A') && (col == 1)) {
    p1 = value;
  }
  else if ((row == 'A') && (col == 2)) {
    p2 = value;
  }
  else if ((row == 'A') && (col == 3)) {
    p3 = value;
  }
  else if ((row == 'A') && (col == 4)) {
    p4 = value;
  }
  else if ((row == 'A') && (col == 5)) {
    p5 = value;
  }
  else if ((row == 'B') && (col == 1)) {
    p6 = value;
  }
  else if ((row == 'B') && (col == 2)) {
    p7 = value;
  }
  else if ((row == 'B') && (col == 3)) {
    p8 = value;
  }
  else if ((row == 'B') && (col == 4)) {
    p9 = value;
  }
  else if ((row == 'B') && (col == 5)) {
    p10 = value;
  }
  else if ((row == 'C') && (col == 1)) {
    p11 = value;
  }
  else if ((row == 'C') && (col == 2)) {
    p12 = value;
  }
  else if ((row == 'C') && (col == 3)) {
    p13 = value;
  }
  else if ((row == 'C') && (col == 4)) {
    p14 = value;
  }
  else if ((row == 'C') && (col == 5)) {
    p15 = value;
  }
  else if ((row == 'D') && (col == 1)) {
    p16 = value;
  }
  else if ((row == 'D') && (col == 2)) {
    p17 = value;
  }
  else if ((row == 'D') && (col == 3)) {
    p18 = value;
  }
  else if ((row == 'D') && (col == 4)) {
    p19 = value;
  }
  else if ((row == 'D') && (col == 5)) {
    p20 = value;
  }
  else if ((row == 'E') && (col == 1)) {
    p21 = value;
  }
  else if ((row == 'E') && (col == 2)) {
    p22 = value;
  }
  else if ((row == 'E') && (col == 3)) {
    p23 = value;
  }
  else if ((row == 'E') && (col == 4)) {
    p24 = value;
  }
  else {
    p25 = value;
  }
}
// Changes the value of adjacent positions.
void changeAdjacents(char row, int col, char value) {
  if ((getValue(row, col - 1) != ' ') && (getValue(row, col - 1) != '~')) {
      setValue(row, col - 1, value);
  }
  if ((getValue(row, col + 1) != ' ') && (getValue(row, col + 1) != '~')) {
      setValue(row, col + 1, value);
  }
  if ((getValue(row - 1, col - 1) != ' ') && (getValue(row - 1, col - 1) != '~')) {
      setValue(row - 1, col - 1, value);
  }
  if ((getValue(row - 1, col) != ' ') && (getValue(row - 1, col) != '~')) {
      setValue(row - 1, col, value);
  }
  if ((getValue(row - 1, col + 1) != ' ') && (getValue(row - 1, col + 1) != '~')) {
      setValue(row - 1, col + 1, value);
  }
  if ((getValue(row + 1, col - 1) != ' ') && (getValue(row + 1, col - 1) != '~')) {
      setValue(row + 1, col - 1, value);
  }
  if ((getValue(row + 1, col) != ' ') && (getValue(row + 1, col) != '~')) {
      setValue(row + 1, col, value);
  }
  if ((getValue(row + 1, col + 1) != ' ') && (getValue(row + 1, col + 1) != '~')) {
      setValue(row + 1, col + 1, value);
  }
}
// Checks if the destination is immediatell adjacent to the current position.
bool isImmediateAdjacent(char row1, int col1, char row2, int col2) {
    if ((row2 == row1) && (col2 == col1 - 1)) {
        return true;
    }
    else if ((row2 == row1) && (col2 == col1 + 1)) {
        return true;
    }
    else if ((row2 == row1 - 1) && (col2 == col1 - 1)) {
        return true;
    }
    else if ((row2 == row1 - 1) && (col2 == col1)) {
        return true;
    }
    else if ((row2 == row1 - 1) && (col2 == col1 + 1)) {
        return true;
    }
    else if ((row2 == row1 + 1) && (col2 == col1 - 1)) {
        return true;
    }
    else if ((row2 == row1 + 1) && (col2 == col1)) {
        return true;
    }
    else if ((row2 == row1 + 1) && (col2 == col1 + 1)) {
        return true;
    }
    else {
        return false;
    }
}
// Checks if the destination is at most 2 spaces away from the current position.
bool isCloseEnoughToMove(char row1, int col1, char row2, int col2) {
    if (isImmediateAdjacent(row1, col1, row2, col2)) {
        return true;
    }
    else if ((row2 == row1) && (col2 == col1 - 2)) {
        return true;
    }
    else if ((row2 == row1) && (col2 == col1 + 2)) {
        return true;
    }
    else if ((row2 == row1 - 2) && (col2 == col1 - 2)) {
        return true;
    }
    else if ((row2 == row1 - 2) && (col2 == col1)) {
        return true;
    }
    else if ((row2 == row1 - 2) && (col2 == col1 + 2)) {
        return true;
    }
    else if ((row2 == row1 + 2) && (col2 == col1 - 2)) {
        return true;
    }
    else if ((row2 == row1 + 2) && (col2 == col1)) {
        return true;
    }
    else if ((row2 == row1 + 2) && (col2 == col1 + 2)) {
        return true;
    }
    else {
        return false;
    }
}
// Checks if user entered a valid board position.
bool isValidInput(char row1, int col1, char row2, int col2) {
    // Checks user input for accepted values of row and columns
    if ((row1 < 'A') || (row1 > 'E') || (col1 < 1) || (col2 > 5) ||\
        (row2 < 'A') || (row2 > 'E') || (col2 < 1) || (col2 > 5)) {
        return false;
    }
    else {
        return true;
    }
}
//-----------------------------------------------------------------------------------------
int main() {
    // Set initial values for the global board variables to all be blank
    p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16=p17=p18=p19=p20=p21=p22=p23=p24=p25= ' ';
    // Set corner starting positions
    p1=p25= 'X';
    p5=p21= 'O';
    
    // Variables to store user input for current row and column, and destination row and column
    char currentRow, destRow, tempVal;
    int currentCol, destCol, countO, countX;
    int moveNumber = 1;
    bool xTurn = false;
    countO = countX = 2;
    
    cout << "Welcome to the 2-player game of Contagion. \n"
         << endl;
    
    if (p14 != ' ') {
        cout << "error here" << endl;
    }
    // Main loop to play game. Checks if board is not filled and both opponents still have a piece on the board.
    while(((countX + countO) < 25) && (countX != 0) && (countO != 0)) {
        
        // Display board and handle first character of user input
        displayBoard();
        cout << moveNumber << ". ";
        if (moveNumber % 2 != 0) {
            cout << "Enter 'i' for instructions, 'x' to exit, or move for X: ";
            xTurn = true;
        }
        else {
            cout << "Enter 'i' for instructions, 'x' to exit, or move for O: ";
            xTurn = false;
        }
        cin >> currentRow;
        currentRow = toupper(currentRow);
      
        // Check to see if user input was 'i' for instructions or 'x' to exit
        if( currentRow == 'I') {
            displayInstructions();
            continue;       // Loop back up to retry move
        }
        else if( currentRow == 'X') {
            break;  // Break out of enclosing loop, to exit the game.
        }
        else if (currentRow == 'P') {
            moveNumber += 1;
            continue;
        }
        else {
            // User input was not 'i' for instructions or 'x' to exit, so a move is being made
            cin >> currentCol;
            cin >> destRow;
            destRow = toupper(destRow);
            cin >> destCol;
            tempVal = getValue(currentRow, currentCol); // *** Abhinav: Should use more meaningful variable name than tempVal
            if (!isValidInput(currentRow, currentCol, destRow, destCol)) {
                cout << "*** Invalid move. Either your starting point or destination is invalid.\n"\
                    << "    Enter only rows A - E, and columns 1 - 5. Please retry." << endl;
                continue;
            }
            if (((xTurn == true) && (tempVal != 'X')) || ((xTurn == false) && (tempVal != 'O'))) {
                cout << "*** Invalid move.  Current piece must belong to you. Please retry." << endl;
                continue;
            }
            if (getValue(destRow, destCol) != ' ') {
                cout << "*** Invalid move.  Destination must be empty. Please retry." << endl;
                continue;
            }
            if (isCloseEnoughToMove(currentRow, currentCol, destRow, destCol)) {
                setValue(destRow, destCol, tempVal);
                if (!isImmediateAdjacent(currentRow, currentCol, destRow, destCol)) {
                    setValue(currentRow, currentCol, ' ');
                }
                changeAdjacents(destRow, destCol, tempVal);
                moveNumber += 1;
            }
            else {
              cout << "*** Invalid move.  A move must be one or two squares away. Please retry." << endl;
            }
        }
        countO = countX = 0;
        for (char I = 'A'; I <='E'; ++I) {
            for(int j = 1; j <= 5; ++j) {
                if (getValue(I, j) == 'X') {
                    ++countX;
                }
                else if (getValue(I, j) == 'O') {
                    ++ countO;
                }
                else {
                    countX = countX;
                    countO = countO;
                }
            }
        }
    } //end while loop
    displayBoard();
    if (countX > countO) {
        cout << "X Wins!\n" << endl;
    }
    else if (countX < countO) {
        cout << "O Wins!\n" << endl;
    }
    else {
        cout << "Tie game.\n" << endl;
    }
    cout << "Exiting program..." << endl;

    return 0;
} // end main()

