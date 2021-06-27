//
// Created by Sun,Minqi on 2021/6/27.
//

#pragma once

#include "util.h"

namespace memento {
    class Memento {
        int _balance;
    public:
        explicit Memento(int balance) : _balance(balance) {}

        friend class BankAccount;
    };

    class BankAccount {
        int _balance;
        size_t _current;
        //这里用vector而不是stack的原因是,需要redo和undo反复出现的时候不需要释放/申请内存
        std::vector<std::shared_ptr<Memento>> _state;
    public:
        explicit BankAccount(int balance) : _balance(balance) {
            _state.emplace_back(std::make_shared<Memento>(_balance));
            _current = 0;
        }

        std::shared_ptr<Memento> deposit(int amount) {
            _balance += amount;
            auto p = std::make_shared<Memento>(_balance);
            _state.emplace_back(p);
            _current = _state.size() - 1;
            return p;
        }

        void restore(const std::shared_ptr<Memento> &m) {
            if (m) {
                _balance = m->_balance;
                _state.emplace_back(m);
                _current = _state.size() - 1;
            }
        }

        int balance_undo() {
            if (_current > 0) {
                --_current;
                _balance = _state[_current]->_balance;
                return 0;
            } else {
                return -1;
            }
        }

        int balance_redo() {
            if (_current < _state.size() - 1) {
                ++_current;
                _balance = _state[_current]->_balance;
                return 0;
            } else {
                return -1;
            }
        }

        friend std::ostream &operator<<(std::ostream &os, BankAccount &ac) {
            os << "Account balance = " << ac._balance << ", state=" << ac._state.size() << ", current=" << ac._current
               << std::endl;
            return os;
        }
    };


}