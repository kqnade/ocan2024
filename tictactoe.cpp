#include <iostream>
#include <vector>

// 3x3のグリッドを表示する関数
void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -----\n";
    }
}

// ゲームの勝者をチェックする関数
char checkWinner(const std::vector<std::vector<char>>& board) {
    // 横と縦のチェック
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // 斜めのチェック
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // 引き分けまたはゲーム続行
    return ' ';
}

// すべてのマスが埋まっているかチェックする関数
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char player = 'X';
    char winner = ' ';

    std::cout << "三目並べゲームへようこそ！\n";
    while (winner == ' ' && !isBoardFull(board)) {
        printBoard(board);
        int row, col;
        std::cout << "プレイヤー " << player << ", 行と列を選択してください (例: 0 1): ";
        std::cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "無効な入力です。もう一度試してください。\n";
            continue;
        }

        board[row][col] = player;
        winner = checkWinner(board);

        // プレイヤーを交代
        player = (player == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    if (winner != ' ') {
        std::cout << "プレイヤー " << winner << " の勝利です！\n";
    } else {
        std::cout << "引き分けです！\n";
    }

    return 0;
}
