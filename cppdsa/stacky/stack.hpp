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
            if (this == &other) {
                return;
            }
            
            this->size = other.size;
            this->CAP = other.CAP;
            this->arr = new T[size];

            for (int i = 0; i < other.size; i++) {
                this->arr[i] = other.arr[i];
            }
        }

        //destructor
        ~Stack() {
            destructor();
        }

        //destructor mimic
        void destructor() {
            std::cout << this->arr << '\n';
            delete [] arr;
            // this->arr = nullptr;
        }

        //operator = 
        const Stack<T> operator= (const Stack<T> &other) {
            std::cout << "test1 " << &other << ' ' << arr << '\n';
            if (this != &other) {
                std::cout << "test2 " << &other << ' ' << arr << '\n';
                destructor();
                std::cout << "test3 " << &other << ' ' << arr << '\n';
                copy(other);
                std::cout << "test4 " << &other << ' ' << arr << '\n';
            }
            return *this;
            std::cout << "test5\n";
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
                delete [] temp;
                temp = nullptr;
            } 

            arr[size++] = element;
            
        }

        //pop
        T pop() {
            T temp = this->arr[size - 1];
            size--;
            return temp;
        }

        //peak
        T peak() {
            return this->arr[size - 1];
        }

        //get
        T get(int index) {
            return this->arr[index];
        }

        //set
        void set(int index, T element) {
            this->arr[index] = element;
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
            for (int i = 0; i < size; i++) {
                std::cout << this->arr[i] << ' ';
            }
            std::cout << '\n';
        }

        //clear - call destructor
        void clear() {
            destructor();
        }

        //address
        void address() {
            std::cout << this->arr << '\n';
        }
};

#endif