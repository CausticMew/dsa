#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class Stack {
    private:
        int size;
        int CAP;
        T* arr;

    public:
        //default constructor
        Stack() {
            this->size = 0;
            this->CAP = 10;
            this->arr = new T[CAP];
        }

        //copy constructor
        Stack(const Stack<T> &other) {
            copy(other);
        }

        //copy constructor mimic
        void copy(const Stack<T> &other) {
            this->size = other.size;

            this->arr = new T[size];

            for (int i = 0; i < other.size; i++) {
                this->arr[i] = other[i];
            }
        }

        //destructor
        ~Stack() {
            destructor();
        }

        //destructor mimic
        void destructor() {
            this->size = 0;
            delete [] arr;
        }

        //operator = 
        const Stack<T> operator= (const Stack<T> &other) {
            if (this != &other) {
                destructor();
                copy(other);
            }
        }

        //push
        void push(T element) {

            if (this->size == CAP) {
                T* temp = new T[CAP * 2];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                destructor();
                this->arr = temp;
                temp = nullptr;
                delete [] temp;
            } else {
                arr[size] = element;
            }
            size++;
        }

        //pop
        T pop() {

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

        }

        //length
        int length() {
            return size;
        }

        //print
        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << this->arr[i] << ' ';
            }
            std::cout << '\n';
        }

        //clear - call destructor
        void clear() {

        }
};

#endif