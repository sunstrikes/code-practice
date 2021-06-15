//
// Created by Sun,Minqi on 2021/6/15.
//

#pragma once

#include "../util.h"

namespace command {
    /*
     * 命令模式:
     * 当我们改变一个类成员的时候, 如果直接调用set方法, 无法保留之前的更改记录
     * 从而无法回滚到之前的特定状态, 对于类似交易这种场景无法适用.
     * command模式用来替代数据对象的set/get方法, 保留历史更改
     */
    struct Account {
    private:
        int balance = 0;
        int overdraft_limit = -500;
    public:
        void deposit(int amount) {
            balance += amount;
            std::cout << "deposit succeed, total:" << balance << std::endl;
        }

        bool withdraw(int amount) {
            if (balance - amount > overdraft_limit) {
                balance -= amount;
                std::cout << "withdraw succeed, total:" << balance << std::endl;
                return true;
            }
            std::cout << "withdraw failed" << std::endl;
            return false;
        }
    };

    struct Command {
        virtual void call() = 0;

        virtual void undo() = 0;
    };

    struct BankCommand : Command {
    private:
        bool _withdraw_succeed = false;
        Account &_account;
        int _amount;
    public:
        enum Action {
            deposit, withdraw
        } _action;
        BankCommand(Account &account, Action action, const int amount) : _account(account), _action(action),
                                                                         _amount(amount) {}

        [[nodiscard]] void call() override {
            switch(_action) {
                case Action::deposit:
                    _account.deposit(_amount);
                    break;
                case Action::withdraw:
                    _withdraw_succeed = _account.withdraw(_amount);
                    break;
            }
        }
        void undo() override {
            switch(_action) {
                case deposit:
                    _account.withdraw(_amount);
                    break;
                case withdraw:
                    if (_withdraw_succeed) {
                        _account.deposit(_amount);
                    }
                    break;
            }
        }
    };

}