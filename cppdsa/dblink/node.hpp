#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
struct node {
    node<T>* next;
    node<T>* prev;
    T value;

    node() {
        this->next = nullptr;
        this->prev = nullptr;
    }

    node(T value) {
        this->next = nullptr;
        this->prev = nullptr;
        this->value = value;
    }
};

#endif