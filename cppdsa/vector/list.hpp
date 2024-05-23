#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>


template <typename T>
class List{
    private:
        int size;
        int MAX;
        T arr[];

    public:
        //constructor
        List() {
            this->MAX = 10;
            this->size = 0;
            this->arr = new T[MAX];
        }

        //custom constructor
        List(int CAP) {
            this->MAX = CAP;
            this->size = 0;
            this->arr = new T[CAP];
        }

        //copy constructor
        // List(const T &other[]) {
            
        // }

        //copy constructor mimic
        // void copy(const T &other[]) {

        // }

        //operator = 
        // const operator= (const T &other) {
        //     if (this != &other) {
        //         destructor();
        //         copy(other);
        //     }
        // }

        //destructor
        ~List() {

        }

        //destructor mimic
        void destructor() {

        }

        //isEmpty
        bool isEmpty() {
            // if (this->size == 0) {
            //     return true;
            // }
            // return false;
            return size == 0;
        }

        //size/length
        int length() {
            return size;
        }

        //push
        void push(T element, int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
            }

            if (isEmpty() && index != 0) {
                std::cout << "Array is empty, index: " << index << " is greater than 0.\n";
                return;
            }

            if (MAX <= size) {
                T temp = new T[MAX *= 2];
                for (int i = 0; i < size; i++) {
                    temp[i] = this->arr[i];
                }
                this->arr = temp;
            }

            for (int i = size; i > index; i--) {
                    arr[i] == arr[i - 1];
            }
            this->arr[index] = element;

            size++;
        }

        //remove
        T remove(int index) {

        }

        //print
        void print() {

        }

        //get
        T get(int index) {

        }

        //set
        T set(int index, T element) {

        }

        //indexOf
        int indexOf(T element) {

        }
};


#endif