//
// Created by Sun,Minqi on 2021/6/22.
//

#pragma once

#include "util.h"

namespace iterator {

    template<typename T>
    struct BinaryTree;

    template<typename T>
    struct Node {
        T value;
        Node<T> *left = nullptr;
        Node<T> *right = nullptr;
        Node<T> *parent = nullptr;
        BinaryTree<T> *tree = nullptr;

        explicit Node(T value) : value(std::move(value)) {}

        Node(T value, Node<T> *l, Node<T> *r) : value(std::move(value)), left(l), right(r) {
            left->parent = this;
            right->parent = this;
            left->tree = right->tree = tree;
        }

        void set_tree(BinaryTree<T> *t) {
            tree = t;
            if (left) left->tree = tree;
            if (right) right->tree = tree;
        }
    };

    template<typename T>
    struct PreOrderIterator;

    template<typename T>
    struct BinaryTree {
        Node<T> *_root = nullptr;

        explicit BinaryTree(Node<T> *root) : _root(root) {
            _root->set_tree(this);
        }

        PreOrderIterator<T> begin() {
            auto p = _root;
            while(p->left) {
                p = p->left;
            }
            return PreOrderIterator<T>{p};
        }

        PreOrderIterator<T> end() {
            return PreOrderIterator<T>{nullptr};
        }
    };

    template<typename T>
    struct PreOrderIterator {
    public:
        Node<T> *current;
        explicit PreOrderIterator(Node<T> *curr) : current(curr) {}

        bool operator!=(const PreOrderIterator<T> &other) {
            return current != other.current;
        }

        Node<T>& operator*() { return *current; }

        PreOrderIterator<T> &operator++() {
            if (current->right) {
                current = current->right;
                while (current->left) {
                    current = current->left; //前序遍历
                }
            } else {
                auto p = current->parent;
                while (p && current == p->right) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }
    };
}