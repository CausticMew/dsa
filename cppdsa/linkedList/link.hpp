#ifndef LINK_HPP
#define LINK_HPP
#include "node.hpp"

template<typename T>
class Link {
    private:
        node<T>* head;
        node<T>* tail;
        int size;

    public:
    //default constructor
    Link() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    //copy constructor
    Link(const Link<T> &other) {
        copy(other);
    }


    //copy mimic
    void copy(const Link<T> &other) {
        if (other.head == nullptr) {
            this->head = nullptr;
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

    //copy mimic2
    void copy2(const Link<T> &other) {
        if (other.head == nullptr) {
            this->head = nullptr;
            this->size = 0;

            return;
        }

        node<T>* oWalker = other.head;
        this->head = new node<T>(oWalker->value);
        node<T>* tWalker = this->head;

        while(oWalker->next != nullptr) {
            oWalker = oWalker->next;
            push(oWalker->value);
            tWalker = tWalker->next;
        }

        this->tail = other.tail;
        this->size = other.size;
    }

    //destructor
    ~Link() {
        destroy();
    }

    //destructor mimic - set size to 0
    void destroy(){
        while(this->head != nullptr) {
            node<T>* walker = this->head;
            head = walker->next;
            size--;
            delete walker;
        }
    }

    //destructor mimic2 - set size to 0
    void destroy2(){
        while(this->head != nullptr) {
            remove(0);
        }
    }
    

    //operator overload = 

    //get - gets element at index
    T get(int index) {
        if (isEmpty()) {
            std::cout << "Link is empty!\n";
            return static_cast<T>(-1);
        }

        if (index < 0 || index >= size) {
            std::cerr << "Index is out of bounds.\n";
            return static_cast<T>(-1);
        }

        node<T>* walker = this->head;
        
        for (int i = 0; i < index; i++) {
            walker = walker->next;
        }

        return walker->value;
    }

    //set - sets element at index
    T set(int index, T element) {
        if ((index < 0 || index >= size) && !isEmpty()) {
            std::cerr << "Index is out of bounds.\n";
            return static_cast<T>(-1);
        }

        node<T>* walker = this->head;

        if (isEmpty()) {
            std::cout << "Link is empty, setting at index 0.\n";
            node<T>* set = new node<T>(element);
            size++;
            this->head = set;
            
            return static_cast<T>(-1);
        }
        
        for (int i = 0; i < index; i++) {
            walker = walker->next;
        }

        T temp = walker->value;
        walker->value = element;

        return temp;
    }

    //length
    int length() {
        return size;
    }

    //isEmpty
    bool isEmpty() {
        return this->head == nullptr;
    }

    //push
    void push(T element) {
        node<T>* pushed = new node<T>(element);
        size++;
        if (this->head == nullptr) {
            this->head = pushed;
            this->tail = tail;
        } else {
            node<T>* walker = head;
            while(walker->next != nullptr) {
                walker = walker->next;
            }
            walker->next = pushed;
            this->tail = pushed;
        }
    }

    //addAt
    void addAt(int index, T element) {
        node<T>* added = new node<T>(element);

        if (index == 0) {
        added->next = this->head;
        this->head = added;
        }

        int in = 0;
        node<T>* walker = this->head;
        
        while(walker != nullptr && in < index - 1) {
            walker->next = walker;
            in++;
        }

        added->next = walker->next;
        walker->next = added;
        size++;

        while(walker->next != nullptr) {
            walker = walker->next;
        }

        this->tail = walker;
    }

    //remove
    T remove(int index) {
        if (isEmpty()) {
            std::cout << "Link is empty!\n";
            return static_cast<T>(-1);
        }

        if (index < 0 || index >= size) {
            std::cerr << "Index is out of bounds.\n";
            return static_cast<T>(-1);
        }

        node<T>* walker = this->head;
        T value;

        if (index == 0) {
            value = walker->value;
            head = head->next;
        } else {
            node<T>* prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = walker;
                walker = walker->next;
            }

            value = walker->value;

            if (index < size - 1) {
                prev->next = walker->next;
            } else {
                prev->next = nullptr;
            }
        }

        size--;

        node<T>* tWalker = this->head;

        while(tWalker->next != nullptr) {
            tWalker = tWalker->next;
        }
        
        this->tail = tWalker;

        delete walker;
        return value;
    }

    //indexOf - returns index takes in element, gives the index of the first ocurrence
    int indexOf(T element) {
        node<T>* walker = this->head;
        int i = 0;

        while(walker != nullptr) {
            if (walker->value == element) {
                std::cout << "Element found at index " << i << '\n';
                return i;
            }
            walker = walker->next;
            i++;
        }

        std::cout << "Element not found!\n";
        return -1;
    }

    //indexesOf - returns an array 
    int* indexesOf(T element) {
        node<T>* walker = this->head;
        node<T>* sWalker = this->head;
        int SIZE = 0;

        while(sWalker != nullptr) {
            if (sWalker->value == element) {
                SIZE++;
            }
            sWalker = sWalker->next;
        }

        int* arr = new int[SIZE];
        std::cout << "Size: " << SIZE << '\n';
        int i = 0;
        int j = 0;

        std::cout << '[';
        
        while(walker != nullptr) {
            if (walker->value == element) {
                std::cout << i << ' ';
                arr[j] = i;
                j++;
            }
            walker = walker->next;
            i++;
        }

        std::cout << "]\n";

        return arr;
    }

    //reverse - reverses linked Link

    //print
    void print() {
        node <T>* walker = head;
        while(walker != nullptr) {
            std::cout << walker->value << ' ';
            walker = walker->next;
        }
        std::cout << '\n';
    }

    //search
    bool search(T element) {
        node <T>* walker = head;
        while(walker != nullptr) {
            if (walker->value == element) {
                std::cout << "Element Found!\n";
                return true;
            }
            walker = walker->next;
        }
        std::cout << "Element Not Found!\n";
        return false;
    }

    void printTail() {
        std::cout << "Tail Value: " << tail->value << '\n';
    }
};

#endif