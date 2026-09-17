#include <iostream>
#include <vector>
#include <string>
#include <queue>

constexpr int HEIGHT = 6;
constexpr int WIDTH = 7;

// 一手を記録.
struct Move {
    private:
    int idx_;
    int player_;
    int row_;
    int col_;
    
    public:
    Move (int& idx, int& player, int& row, int& col) {
        idx_ = idx;
        player_ = player;
        row_ = row;
        col_ = col;
    }

    int get_idx() {return idx_;}
    int get_player() {return player_;}
    int get_row() {return col_;}
    int get_col() {return col_;}
};


class Board {
    private:
    std::vector<std::vector<int>> data;
    std::queue<int> players;
    int first_player;

    public:
    // 引数がない場合, 全ての要素を0で初期化したBoardを作成する.
    Board() : Board(std::vector<std::vector<int>> (HEIGHT, std::vector<int>(WIDTH, 0))) {}

    Board(const std::vector<std::vector<int>> &board_vec) {
        // board_vecはHEIGHT * WIDTHの二次元vector. 右辺値でもよい.
        if (board_vec.size() == HEIGHT && board_vec.at(0).size() == WIDTH) {
            data = board_vec;
        // boardの形がHEIGHT * WIDTHでない場合に発生するエラー.
        } else {
            throw std::invalid_argument("'board_vec' must have a shape of ("
                + std::to_string(HEIGHT)
                + ", "
                + std::to_string(WIDTH)
                + ")");
        }

        // playerはデフォルトで先手: 1, 後手: 2
        std::vector<int> players_vec{1, 2};
        _init_players(players_vec);
    }

    int _init_players(std::vector<int> &players_vec) {
        if (players_vec.size() != 2) {
            throw std::invalid_argument("Argument 'players_vec' must have 2 elements.");
        }
        // プレイヤー(int)をキューに追加
        for (int i=0; i<2; i++) {
            players.push(players_vec.at(i));
        }
        
        // 先手を記憶
        first_player = players.front();

        return 0;
    }

    int at(int i, int j) {
        return data.at(i).at(j);
    }

    int move(int col, int player) {
        // playerがcol列目(col = 0, 1, ... , WIDTH)にコインを落とす.

        // 引数をチェック
        if (col >= 0 && col < WIDTH) {
            throw std::invalid_argument("'col' must be greater than 0 and less than"
                                        + std::to_string(WIDTH)
                                        + " col: "
                                        + std::to_string(col));
        }
    // --- ここから ---
    
    // --- ここまで ---

    return 0;

    }

    int judge(Move &move) {
        // --- ここから ---
        
        // --- ここまで ---
    }

    int print() {
        // board.dataをコンソールに出力する.
        for (int i=0; i<HEIGHT; i++) {
            for (int j=0; j<WIDTH; j++) {
                std::cout << data.at(i).at(j);
                std::cout << " ";
            }
            printf("\n");
        }
        return 0;
    }
};

int main(void) {
    return 0;
}