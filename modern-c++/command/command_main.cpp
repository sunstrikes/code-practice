//
// Created by Sun,Minqi on 2021/6/15.
//

#include "command.h"
using namespace command;
using namespace std;
int main() {
    cout << "Command Pattern:" << endl;
    Account account;
    vector<BankCommand> com_vec;
    com_vec.emplace_back(BankCommand(account, BankCommand::deposit, 500));
    com_vec.emplace_back(BankCommand(account, BankCommand::withdraw, 1000));
    for (auto& com: com_vec) {
        com.call();
    }
    for (auto& com: com_vec) {
        com.undo();
    }

    cout << endl << "Composite Command Pattern:" << endl;
    Account from; from.balance = 1000;
    Account to;
    MoneyTransferCommand trans_com{from, to, 1500};
    trans_com.call();
    cout << "from: " << from.balance << "  to: " << to.balance << endl;
    trans_com.undo();
    cout << "from: " << from.balance << "  to: " << to.balance << endl;

    return 0;
}