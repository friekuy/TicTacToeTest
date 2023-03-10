// This program will create a simple Tic Tac Toe game in the console.

#include <iostream>

void drawBoard(const char square[]);
void mark(char square[], const char &player);
int checkWin(char square[]);

int main()
{
    // Game loop is as follows:
    // 
    // Draw the board
    // Take player input
    // Update the board
    // if win end game and clear board
    // Switch player

    char player{ 'O' };
    char square[9]{ '1', '2', '3',
                    '4', '5', '6',
                    '7', '8', '9' };

    do {
        player = (player == 'X') ? 'O' : 'X';

        drawBoard(square);
        mark(square, player);
    } while (checkWin(square) == -1);

    if (checkWin(square) == 1)
        std::cout << "Player " << player << " wins!\n";
    else
        std::cout << "Draw!\n";

    std::cin.get();

    return 0;
}

// This function draws the tic tac toe board based on the values of the square array.
void drawBoard(const char square[]) {
        std::cout << "TIC TAC TOE! LET'S GO!\n"
        << "         |         |         \n"
        << "    " << square[0] << "    |    " << square[1] << "    |    " << square[2] << '\n'
        << "_________|_________|_________\n"
        << "         |         |         \n"
        << "    " << square[3] << "    |    " << square[4] << "    |    " << square[5] << '\n'
        << "_________|_________|_________\n"
        << "         |         |         \n"
        << "    " << square[6] << "    |    " << square[7] << "    |    " << square[8] << '\n'
        << "         |         |         \n";
}

// This function takes valid user input and draws the player mark on the corresponding square on the board.
// If the chosen square is already marked, the player must choose a different square.
void mark(char square[], const char &player) {
    int choice{};
    bool validIn{false};

    std::cout << "Player " << player << "'s turn\n" << "Choose a square to mark: ";

    do {
        if (!(std::cin >> choice)) {
            system("cls");
            drawBoard(square);
            std::cout << "That is not a valid numerical character. Please try again!\n"
                << "Player " << player << "'s turn\n" << "Choose a square to mark: ";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if (choice < 1 || choice > 9) {
            system("cls");
            drawBoard(square);
            std::cout << "This square does not exist. Please try again!\n"
                << "Player " << player << "'s turn\n" << "Choose a square to mark: ";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if (square[choice - 1] == 'X' || square[choice - 1] == 'O'){
            system("cls");
            drawBoard(square);
            std::cout << "This square is already marked. Please try again!\n"
                << "Player " << player << "'s turn\n" << "Choose a square to mark: ";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else validIn = true;
    } while (!validIn);

    std::cin.ignore(INT_MAX, '\n');

    // Array index starts at 0 which corresponds to square 1, so subtract 1 to the player's choice.
    square[choice - 1] = player;
    
    system("cls");
}

// This function checks the board for a line of three like marks to determine if the game is a draw,
// won, or undetermined.
int checkWin(char square[]) {
    if (square[0] == square[1] && square[0] == square[2] ||
        square[0] == square[4] && square[0] == square[5] ||
        square[0] == square[3] && square[0] == square[6] ||
        square[0] == square[4] && square[0] == square[8] ||
        square[1] == square[4] && square[1] == square[7] ||
        square[2] == square[5] && square[2] == square[8] ||
        square[2] == square[4] && square[2] == square[6] ||
        square[3] == square[4] && square[3] == square[5] ||
        square[6] == square[7] && square[6] == square[8])
        return 1;                                           // A line of marks is found so a player won.

    for (int i{ 0 }, marks{}; i < 9; i++) {
        if (square[i] == 'X' || square[i] == 'O')
            marks++;
        if (marks == 9)
            return 0;                                       // All squares are marked so it is a draw.
    }

        return -1;                                          // If neither a draw or a win, the game continues.                        
}