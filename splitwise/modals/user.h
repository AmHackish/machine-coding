#include<bits/stdc++.h>
using namespace std;
    
#ifndef USER_H
#define USER_H

class User {
private:
    string user_email;
    string user_mobile_no;

public:
    int user_id;
    map<int, double> owed_users;
    double user_current_balance;
    string user_name;

    User() {}

    User(string name, int id, string email, string mobile_no) {
        user_name = name;
        user_id = id;
        user_email = email;
        user_mobile_no = mobile_no;
        user_current_balance = 0;
    }
};

#endif 