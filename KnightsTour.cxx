#include <iostream>
#include <vector>
#include <iomanip>

constexpr int N{8};
static std::vector<int> xMove {2, 1, -1, -2, -2, -1,  1,  2};
static std::vector<int> yMove {1, 2,  2,  1, -1, -2, -2, -1};


bool isLegalMove(int x, int y, std::vector<std::vector<int>> &board) {
   return ( x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

int knightTour(int x, int y, int move, std::vector<std::vector<int>> &board) {
    int xNextMove, yNextMove;
    if(move == N*N) return true;
    
    for(int k = 0; k < N; k++) {
        xNextMove = x + xMove[k];
        yNextMove = y + yMove[k];
        if(isLegalMove(xNextMove, yNextMove, board)) {
            board[xNextMove][yNextMove] = move;
            if(knightTour(xNextMove, yNextMove, move+1, board) == true)
                return true;
            else
                board[xNextMove][yNextMove] = -1;
        }
   }
   return -1;
}

bool findKnightTour() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N,-1));
    board[0][0] = 0;
    if (knightTour(0, 0, 1, board) == -1) {
        return false;
    }else {
        for (int x = 0; x < N; x++){
            for (int y = 0; y < N; y++)
                std::cout << std::setw(3) << board[x][y] << " ";
            std::cout << std::endl;
        }
    }
    return true;
}

int main() {
   findKnightTour();
   return 0;
}