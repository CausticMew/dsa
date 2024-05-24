#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
struct node {
    node<T>* next;
    T value;

    node() {
        this->next = nullptr;
    }

    node(T value) {
        this->next = nullptr;
        this->value = value;
    }
};

#endif