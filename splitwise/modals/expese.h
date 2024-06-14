#ifndef EXPENSE
#define EXPENSE

#include<bits/stdc++.h>
using namespace std;

class Expense {
public:
    int trans_id = 0;
    int total_user;
    double money;
    int lender_id;
    vector<int> borrowers_id;
    string trans_type = "EQUAL";
    vector<double> percentage_share;

    Expense() {}

    Expense(int len_id, double m, int n, vector<int> list, string type) {
        trans_id++;
        lender_id = len_id;
        borrowers_id = list;
        total_user = n;
        money = m;
        trans_type = type;
    }
};

#endif 