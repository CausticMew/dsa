#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>


template <typename T>
class List{
    private:
        T arr[];
        int size;
        
    public:
        //constructor
        List() {

        }

        //copy constructor
        List(const T &other[]) {

        }

        //copy constructor mimic
        void copy(const T &other[]) {

        }

        //operator = 
        const operator= (const T &other) {

        }

        //destructor
        ~List() {

        }

        //destructor mimic
        void destructor() {

        }

        //isEmpty
        bool isEmpty() {

        }

        //size/length
        int size() {

        }

        //push
        void push(T element, int index) {

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



