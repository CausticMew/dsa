#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <algorithm>


template <typename T>
class Vector{
    private:
        int size;
        int MAX;
        T* arr;

    public:
        //constructor
        Vector() {
            this->MAX = 10;
            this->size = 0;
            this->arr = new T[MAX];
        }

        //custom constructor
        Vector(int CAP) {
            this->MAX = CAP;
            this->size = 0;
            this->arr = new T[CAP];
        }

        //copy constructor
        Vector(const Vector<T> &other) {
            copy(other);
        }

        //copy constructor mimic
        void copy(const Vector<T> &other) {
            this->MAX = other.MAX;
            this->size = other.size;

            this->arr = new T[size];

            for (int i = 0; i < other.size; i++) {
                this->arr[i] = other[i];
            }
        }

        //operator = 
        const Vector<T> operator= (const T &other) {
            if (this != &other) {
                destructor();
                copy(other);
            }
        }

        //destructor
        ~Vector() {
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
                temp = nullptr;
                delete [] temp;
            }

            for (int i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
            }
            this->arr[index] = element;

            size++;
        }

        //shrink
        void shrink() {
            if (size / 2 <= MAX) {
                T* temp = new T[MAX /= 2];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                destructor();
                this->arr = temp;
                temp = nullptr;
                delete [] temp;
            }
        }

        //rotate
        void rotate(int index) {
            T temp[size];

            for (int i = 0; i < size; i++) {
                temp[i] = this->arr[i];
            }

            for (int i = 0; i < size - index; i++) {
                this->arr[i] = temp[index + i];
            }

            for (int i = 0; i < index; i++) {
                this->arr[size - index + i] = temp[i];
            }
        }

        //removeRange
        void removeRange(int start, int end) {
            int shift = (end - start + 1);
            for (int i = start; i < size - shift; i++) {
                arr[i] = arr[i + shift];
            }
            size -= (end - start + 1);
        }

        //remove
        T remove(int index) {
            if (index < 0 || index >= size || size == 0) {
                throw std::out_of_range("Index " + std::to_string(index) + " is out of bounds.");
            }

            T removed = this->arr[index];

            for (int i = index; i < size; i++) {
                this->arr[i] = this->arr[i + 1];
            }

            size--;
            return removed;
        }

        T* subArray(int start, int end) {
            T temp[size - end - start + 1];

            int inc = start;
            for (int i = start; i < end; i++) {
                temp[i] = arr[i];
            }
            
            arr = temp;

            return arr;
        }

        void clear() {
            size = 0;
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
            for (int i = 0; i < size; i++) {
                if (element == this->arr[i])
                    return i;
            }

            return -1;
        }

        void reverse() {
            T temp;
            int length = size;
            for (int i = 0; i < size / 2; i++) {
                temp = this->arr[i];
                this->arr[i] = this->arr[length - 1];
                this->arr[length - 1] = temp;
                length--;
            }
        }
};


#endif