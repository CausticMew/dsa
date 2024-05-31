#ifndef LIST_HPP
#define LIST_HPP
#include "node.hpp"

template<typename T>
class List {
    private:
        node<T>* head;
        int size;

    public:
    //default constructor
    List() {
        this->head = nullptr;
        this->size = 0;
    }

    //copy constructor

    //copy mimic

    //destructor

    //destructor mimic

    //operator overload = 

    //get

    //set

    //isEmpty
    bool isEmpty() {
        return this->head == nullptr;
    }

    //push
    void push(T element) {
        node<T>* pushed = new node<T>(element);
        if (this->head == nullptr) {
            this->head = pushed;
        } else {
            node<T>* walker = head;
            while(walker->next != nullptr) {
                walker = walker->next;
            }
            walker->next = pushed;
        }
    }

    //addAt


    //remove

    //clear

    //indexOf

    //indexesOf

    //reverse

    //print
    void print() {
        node <T>* walker = head;
        while(walker != nullptr) {
            std::cout << walker->value << ' ';
            walker = walker->next;
        }
    }
};

#endif