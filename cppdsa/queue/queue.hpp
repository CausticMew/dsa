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
            if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return static_cast<T>(-1);
            }

            T val;
            val = this->head->value;
            this->head = this->head->next;
            size--;
            return val;
        }

        //enqueue
        void enqueue(T element) { 
            node <T>* pushed = new node<T>(element);
            size++;

            if (this->head == nullptr) {
                this->head = pushed;
                this->tail = pushed;
            } else {
                 node<T>* walker = this->tail; 

                pushed->prev = walker;
                walker->next = pushed;
                this->tail = pushed;
            }
        }

        //peak
        T peak() {
            return this->head->value;
        }

        //get
        T get(int index) {
            if (index < 0 || index >= size) {
                std::cerr << "Index is out of bounds.\n";
                return static_cast<T>(-1);
            }

            node <T>* walker = this->head;

            for (int i = 0; i < index; i++) {
                walker =  walker->next;
            }

            return walker->value;
        }

        //set
        void set(int index, T element) {
            if (index < 0 || index >= size) {
                std::cerr << "Index is out of bounds.\n";
                return;
            }

            node <T>* walker = this->head;

            for (int i = 0; i < index; i++) {
                walker = walker->next;
            }

            walker->value = element;
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