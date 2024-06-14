#include<bits/stdc++.h>
using namespace std;
#include "../modals/user.h"

#ifndef USERSERVICE_H
#define USERSERVICE_H

class UserService {
public:
    map<int, User*> users;
    UserService() {
        users.clear();
    }

    void addUser(User *user) {
        users[user->user_id] = user;
    }

    User* getuser(int user_id) {
        if(users.find(user_id) == users.end()) {
            return nullptr;
        }
        return users[user_id];
    }

    string getName(int user_id) {
        if(users.find(user_id) == users.end()) {
            return "User Does not Exist!";
        }
        return users[user_id]->user_name;
    }

    void showUserBalanceById(int user_id) {
        User *u1 = getuser(user_id);
        string name = getName(user_id);
        if(users.find(user_id) == users.end()) {
            cout << "No Balance" << endl;
            return ;
        }
        if(users[user_id]->user_current_balance == 0) {
            cout << "No Balance" << endl;
            return ;
        }
        cout << "Balance of " << name << " " << u1->user_current_balance << endl; 
        for(auto it: users[user_id]->owed_users) {
            if(it.first != user_id)
                cout << name << " owes " << getName(it.first) << ": " << it.second << endl;
        }
    }

    void showBalanceForAllusers() {
        cout << "Show Balance for All Users" << endl;
        if(users.empty()) {
            cout <<  "No Balances" << endl;
        }

        bool flag = 0;
        for(auto it: users) {
            showUserBalanceById(it.first);
        }
        return ;
    }
};
#endif 