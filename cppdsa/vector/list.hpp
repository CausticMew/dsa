#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>


template <typename T>
class List{
    private:
        int size;
        int MAX;
        T* arr;

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
        List(const List<T> &other) {
            copy(other);
        }

        //copy constructor mimic
        void copy(const List<T> &other) {
            this->MAX = other.MAX;
            this->size = other.size;

            this->arr = new T[size];

            for (int i = 0; i < other.size; i++) {
                this->arr[i] = other[i];
            }
        }

        //operator = 
        const operator= (const T &other) {
            if (this != &other) {
                destructor();
                copy(other);
            }
        }

        //destructor
        ~List() {
            destructor();
        }

        //destructor mimic
        void destructor() {
            delete [] arr;
        }

        //isEmpty
        bool isEmpty() {
            // if (this->size == 0) {
            //     return true;
            // }
            // return false;
            return size == 0;
        }

        int getMax() {
            return MAX;
        }

        //size/length
        int length() {
            return size;
        }

        //push
        void push(int index, T element) {
            if (index < 0 || index > size) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
            }

            if (isEmpty() && index != 0) {
                std::cout << "Array is empty, index: " << index << " is greater than 0.\n";
                return;
            }

            if (MAX <= size) {
                T* temp = new T[MAX *= 2];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                destructor();
                this->arr = temp;
            }

            for (int i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
            }
            this->arr[index] = element;

            size++;
        }

        //remove
        T remove(int index) {

        }

        //print
        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << this->arr[i] << ' ';
            }
            std::cout << '\n';

        }

        //get
        T get(int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
            }
            
            return this->arr[index];
        }

        //set
        T set(int index, T element) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
            }

            T temp = this->arr[index];
            this->arr[index] = element;
            return temp;
        }

        //indexOf
        int indexOf(T element) {

        }
};


#endif

// construtor
// copy constructor (use copy mimic)
// copy mimic
// operator= overload ( just destroy and copy)
// destructor (free memory)
// destroy(to be called in destructor)
// isEmpty (check if list is empty)
// length / size (get size)
// push (add element at an index)
// remove (remove at an index)
// print (prints list
// get(get at an index)
// set (replace at an index)
// indexOf(returns the index of an element
