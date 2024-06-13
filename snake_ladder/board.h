#include<bits/stdc++.h>
using namespace std;

class BoardNode {
public:
    string type_value;
    int snake_end;
    int ladder_end;

    BoardNode() {
        type_value = "Empty";
        snake_end = 0;
        ladder_end = 0;
    }
};

class Board {
public:
    vector<BoardNode*> board;
    void initialize(int snake, vector<pair<int,int>> snake_pos, int ladder, vector<pair<int,int>> ladder_pos) {
        board.resize(101);
        for(int i=0; i<101; i++) {
            board[i] = new BoardNode();
        }

        for(int i=0; i<snake; i++) {
            board[snake_pos[i].second]->type_value = "Snake";
            board[snake_pos[i].first]->snake_end = snake_pos[i].second;
        }

        for(int i=0; i<ladder; i++) {
            board[ladder_pos[i].first]->type_value = "ladder";
            board[ladder_pos[i].first]->ladder_end = ladder_pos[i].second;
        }
    }

    int dice_roll() {
        int x = abs(rand()%5)+1;
        return x;
    }

    string findWinner(int n, vector<string> players) {
        map<int,int> pos;
        for(int i=0; i<n; i++) {
            pos[i] = 0;
        }

        int start = 0, winner = 0;
        while(1) {
            if(start == n) {
                start = 0;
            }
            int curr_dice = dice_roll();
            int next_pos = curr_dice+pos[start];
            cout << players[start] << " rolled a " << curr_dice << " and moved from " << pos[start] << " to " << next_pos << endl; 
            if(next_pos == 100) {
                winner = start;
                break;
            }
            else if(next_pos < 100 && next_pos > 0) {
                
                if(board[next_pos]->type_value == "Empty") {
                    pos[start] = next_pos;
                }
                else if(board[next_pos]->type_value == "ladder") {
                    pos[start] = board[next_pos]->ladder_end;
                }
                else {
                    pos[start] = board[next_pos]->snake_end;
                }
            }
            start++;
        }

        return players[start];
    }
};