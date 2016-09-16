#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) : _w(width), _h(height), _food(food) {
        _snake.push_front(make_pair(0, 0));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {

        if (gameOver) return -1;

        int x = _snake.front().first, y = _snake.front().second;
        char c = direction[0];
        if (c == 'U') x--;
        else if (c == 'R') y++;
        else if (c == 'D') x++;
        else y--;
        if (x < 0 || x >= _h || y < 0 || y >= _w) {
            gameOver = true;
            return -1;
        }
        if (eatSelf(x, y)) {
            gameOver = true;
            return -1;
        }
        _snake.push_front(make_pair(x, y));

        if (foodIndex < _food.size() && x == _food[foodIndex].first && y == _food[foodIndex].second) {
            foodIndex++;
            return foodIndex;
        } else {
            _snake.pop_back();
            return foodIndex;
        }
    }
private:

    bool eatSelf(int x, int y) {
        for (int i = 0; i < _snake.size() - 1; i++) {
            auto& p = _snake[i];
            if (p.first == x && p.second == y) {
                return true;
            }
        }
        return false;
    }

    int _w, _h;
    deque<pair<int,int>> _snake;
    vector<pair<int,int>> _food;
    int foodIndex = 0;
    bool gameOver = false;
};

int main() {

    int width = 3, height = 3;
    vector<pair<int,int>> food = {
            make_pair(2, 0),
            make_pair(0, 0),
            make_pair(0, 2),
            make_pair(2, 2),
    };
    SnakeGame snakeGame(width, height, food);

    vector<string> moves = {
            "D", "D", "R", "U", "U", "L", "D", "R", "R", "U", "L", "D"
    };

    for (auto&s : moves) {
        cout << snakeGame.move(s) << endl;
    }

    return 0;
}