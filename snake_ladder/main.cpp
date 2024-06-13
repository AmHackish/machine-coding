#include<bits/stdc++.h>
using namespace std;
#include "board.h"

int main() {

    Board board;

    int snake;
    cin >> snake;

    vector<pair<int,int>> snake_pos(snake);
    for(int i=0; i<snake; i++) {
        cin >> snake_pos[i].first >> snake_pos[i].second;
    }

    int ladder;
    cin >> ladder;

    vector<pair<int,int>> ladder_pos(ladder);
    for(int i=0; i<ladder; i++) {
        cin >> ladder_pos[i].first >> ladder_pos[i].second;
    }

    int n;
    cin >> n;

    vector<string> players(n);
    for(int i=0; i<n; i++) {
        cin >> players[i];
    }

    board.initialize(snake, snake_pos, ladder, ladder_pos);

    cout << "let's begin the game" << endl;
    string winner = board.findWinner(n, players);

    cout << "Winner is " << winner << endl;
    return 0;   
}