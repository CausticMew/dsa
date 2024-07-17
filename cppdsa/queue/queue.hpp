#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"

//dequeue - to remove(to remove from head), enqueue - to add(adding at tail), rest is same, do it with a doubly linked list
template <typename T> 
class Queue {
    private:
        node<T>* head;
        node<T>* tail;
        int size;

    public:
    //default constructor
        Queue() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }

        //copy constructor
        Queue(const Queue<T> &other) {
            copy(other);
        }

        //copy constructor mimic
        void copy(const Queue<T> &other) {
                if (other.head == nullptr) {
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;

                return;
            } 

            node<T>* oWalker = other.head;
            this->head = new node<T>(oWalker->value);
            node<T>* tWalker = this->head;

            while(oWalker->next != nullptr) {
                oWalker = oWalker->next;
                node<T>* pushed = new node<T>(oWalker->value);
                tWalker->next = pushed;
                tWalker = tWalker->next;
            }

            this->tail = other.tail;
            this->size = other.size;
        }

        //destructor
        ~Queue() {
            destructor();
        }

        //destructor mimic
        void destructor() {
            while(this->head != nullptr) {
                node<T>* walker = this->head;
                head = walker->next;
                size--;
                delete walker;
            }
        }

        //operator = 
        const Queue<T> operator= (const Queue<T> &other) {
            if (this != &other) {
                destructor();
                copy(other);
            }
        }

        //dequeue
        T dequeue() {
            
        }

        //enqueue
        void enqueue(T element) { 
            node <T>* pushed = new node<T>(element);

            if (size == 0) {
                this->head = pushed;
                this->tail = tail;
            }

            node<T>* walker = tail; 

            pushed->prev = walker;
            walker->next = pushed;
            this->tail = pushed;
        }

        //peak
        T peak() {
            
        }

        //get
        T get(int index) {
            
        }

        //set
        void set(int index, T element) {
            
        }

        //isEmpty
        bool isEmpty() {
            if (size == 0) {
                return true;
            } else {
                return false;
            }
        }

        //length
        int length() {
            return size;
        }

        //print
        void print() {
            node <T>* walker = head;
            while(walker != nullptr) {
                std::cout << walker->value << ' ';
                walker = walker->next;
            }
            std::cout << '\n';
        }

};

#endif