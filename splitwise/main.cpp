#include<bits/stdc++.h>
#include "modals/user.h"
#include "services/user_service.h"
#include "modals/expese.h"
#include "services/splitmoney_service.h"
using namespace std;


int main() {

    User u1("U1", 1, "u1@gmail.com", "9636982222");
    User u2("U2", 2, "u2@gmail.com", "9636982223");
    User u3("U3", 3, "u3@gmail.com", "9636982224");
    User u4("U4", 4, "u4@gmail.com", "9636982225");
    
    UserService userService;
    userService.addUser(&u1);
    userService.addUser(&u2);
    userService.addUser(&u3);
    userService.addUser(&u4);

    SplitService splitmoney(&userService);

    int q;
    cin >> q;

    while(q--) {
        string input_type;
        cin >> input_type;
        
        if(input_type == "SHOW_USER") {
            int id;
            cin >> id;

            userService.showUserBalanceById(id);
        }
        if(input_type == "SHOW") {
            userService.showBalanceForAllusers();
        }
        if(input_type == "EXPENSE") {
            int len_id;
            cin >> len_id;

            double money;
            cin >> money;

            int n;
            cin >> n;
            vector<int>list(n);
            for(int i=0; i<n; i++) {
                cin >> list[i];
            }
            
            string type;
            cin >> type;
            Expense e1(len_id, money, n, list, type);

            if(type == "EQUAL") {
                splitmoney.splitEqual(&e1);
            }   
            else {
                double total = 0;
                vector<double> share(n);
                for(int i=0; i<n; i++) {
                    cin >> share[i];
                    total += share[i];
                }
                e1.percentage_share = share;
                if(type == "PERCENT" && total == 100) {
                    splitmoney.splitByPercentage(&e1);
                }
                else if(type == "PERCENT" && total != 100) {
                    cout << "INVALID EXPENSE!!" << endl;
                }
                if(type == "EXACT" && total == money) {
                    splitmoney.splitByShare(&e1);
                }
                else if(type == "EXACT" && total != money) {
                    cout << "INVALID EXPENSE!!" << endl;
                }
            }
        }
    }   
    return 0;
}