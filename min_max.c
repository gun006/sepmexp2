#include <stdio.h>
#include <stdlib.h>

int minimax(int board[9], int player) {

// Base cases
if (is_terminal_state(board)) {
return evaluate_board(board);
}

// Recursive cases
int best_score = player == 1 ? -INT_MAX : INT_MAX;
for (int i = 0; i < 9; i++) {
if (board[i] == 0) {
board[i] = player;
int score = minimax(board, -player);
board[i] = 0;
best_score = player == 1 ? max(best_score, score) : min(best_score, score);
}
}

return best_score;
}

int main() {
int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int player = 1; // 1 for X, -1 for O

int best_score = minimax(board, player);

// Make the best move
for (int i = 0; i < 9; i++) {
if (board[i] == 0) {
board[i] = player;
break;
}
}

// Print the board
for (int i = 0; i < 9; i++) {
printf("%d ", board[i]);
}

printf("\n");

return 0;
}
