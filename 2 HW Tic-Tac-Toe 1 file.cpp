#include <iostream>
#include <cstdlib>

using namespace std;

class Game
{
public:
	Game();
	void clearBoard();
	void putMark(int, int);
	bool isWin(int);
	int getWinner();
	void printBoard();
	int getX();
	void checkWinner();
	friend ostream& operator<<(ostream& out, Game& game);

private:
	const int X = 1, O = -1, EMPTY = 0;
	int board[3][3];
	int currentPlayer;
};

int main() {
	Game newGame;					// Creates Game object
	cout << newGame;				// Prints board to console
	newGame.putMark(0, 0);
	/*cout << newGame;
	newGame.putMark(1, 1);
	cout << newGame;
	newGame.putMark(0, 1);
	cout << newGame;
	newGame.putMark(0, 2);
	cout << newGame;
	newGame.putMark(2, 0);
	cout << newGame;
	newGame.putMark(1, 2);
	cout << newGame;
	newGame.putMark(2, 2);
	cout << newGame;
	newGame.putMark(2, 1);
	cout << newGame;
	newGame.putMark(1, 0);*/
	cout << newGame;

	newGame.checkWinner();			// Checks for winner

	return EXIT_SUCCESS;
}

Game::Game() {
	clearBoard();					// Clears board at the startt of the game
}

void Game::checkWinner() {				// Checks for winner and then prints who won
	int winner = getWinner();
	if (winner != EMPTY)
		cout << "\n\n" << (winner == X ? 'X' : 'O') << " wins" << endl;
	else
		cout << " Tie" << endl;
}

void Game::clearBoard() {				// clears board
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = EMPTY;

	currentPlayer = X;
	cout << "New Game Started, Board Cleared.";
}

void Game::putMark(int i, int j) {		// marks row and column with current player and then switches player
	board[i][j] = currentPlayer;
	currentPlayer = -currentPlayer;
}

bool Game::isWin(int mark) {			// checks winning conditions and returns winner if the condition is met
	int win = 3 * mark;
	return ((board[0][0] + board[0][1] + board[0][2] == win)
		|| (board[1][0] + board[1][1] + board[1][2] == win)
		|| (board[2][0] + board[2][1] + board[2][2] == win)
		|| (board[0][0] + board[1][0] + board[2][0] == win)
		|| (board[0][1] + board[1][1] + board[2][1] == win)
		|| (board[0][2] + board[1][2] + board[2][2] == win)
		|| (board[0][0] + board[1][1] + board[2][2] == win)
		|| (board[2][0] + board[1][1] + board[0][2] == win));
}

int Game::getWinner() {					// Checks if there is a winner by calling isWin to check the winning condition
	if (isWin(X)) return X;
	else if (isWin(O)) return O;
	else return EMPTY;
}

void Game::printBoard() {				// Prints board in console
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (board[i][j]) {
			case 1:
				cout << "X";
				break;
			case -1:
				cout << "O";
				break;
			case 0:
				cout << " ";
				break;
			}
			if (j < 2)
				cout << "|";
		}
		if (i < 2)
			cout << "\n-+-+-\n";
	}
}

int Game::getX() {
	return X;
}

ostream& operator<<(ostream& out, Game& game) {		// Overloads << operator and prints board
	out << "\n\n";
	game.printBoard();
	return out;
}
