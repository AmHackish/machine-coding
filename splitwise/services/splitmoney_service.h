#ifndef SPLITSERVICE
#define SPLITSERVICE

#include "../modals/expese.h"
#include "../services/user_service.h"
#include<bits/stdc++.h>
using namespace std;

class SplitService {
public:
    UserService *userService;
    SplitService(UserService *u_service) {
        userService = u_service;
    }
    void splitEqual(Expense *exp) {
        double share_PP = exp->money/exp->total_user;
        User *len_user = userService->getuser(exp->lender_id);
        len_user->user_current_balance += exp->money;
        for(int i=0; i<exp->total_user; i++) {
            User *b_user = userService->getuser(exp->borrowers_id[i]);
            if(b_user == nullptr) {
                cout << "USER DOES NOT EXIT" << endl;
                return ;
            }
            b_user->user_current_balance -= share_PP;
            cout << b_user->user_current_balance  << " ";
            if(len_user->user_id != b_user->user_id)
                b_user->owed_users[len_user->user_id] = b_user->owed_users[len_user->user_id] + share_PP;
        }
    }

    void splitByPercentage(Expense *exp) {
        User *len_user = userService->getuser(exp->lender_id);
        len_user->user_current_balance += exp->money;
        for(int i=0; i<exp->total_user; i++) {
            User *b_user = userService->getuser(exp->borrowers_id[i]);
            if(b_user == nullptr) {
                cout << "USER DOES NOT EXIT" << endl;
                return ;
            }
            double share_PP = ((exp->money)*(exp->percentage_share[i]))/100;
            b_user->user_current_balance -= share_PP;
            cout << b_user->user_current_balance  << " ";
            if(len_user->user_id != b_user->user_id)
                b_user->owed_users[len_user->user_id] = b_user->owed_users[len_user->user_id] + share_PP;
        }
    }

    void splitByShare(Expense *exp) {
        User *len_user = userService->getuser(exp->lender_id);
        len_user->user_current_balance += exp->money;
        for(int i=0; i<exp->total_user; i++) {
            User *b_user = userService->getuser(exp->borrowers_id[i]);
            if(b_user == nullptr) {
                cout << "USER DOES NOT EXIT" << endl;
                return ;
            }
            double share_PP = exp->percentage_share[i];
            b_user->user_current_balance -= exp->percentage_share[i];
            if(len_user->user_id != b_user->user_id)
                b_user->owed_users[len_user->user_id] = b_user->owed_users[len_user->user_id] + share_PP;
        }
    }
};

#endif 