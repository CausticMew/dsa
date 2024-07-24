#include <iostream>
#include "queue.hpp"

int main() {
    Queue<int> q;

    //enqueue and print test
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(13);
    q.print();

    //copy test
    Queue<int> q2(q);

    //dequeue test
    q.dequeue();
    q.print();

    //destructor test
    q.~Queue();
    q.isEmpty();

    //peak test
    std::cout << "Peak Test: " << q2.peak() << '\n';

    //get test
    std::cout << "Get Test: " << q2.get(0) << '\n';
    std::cout << "Get Test: " << q2.get(1) << '\n';
    std::cout << "Get Test: " << q2.get(2) << '\n';

    //set test
    q2.set(0, 8);
    q2.set(1, 12);
    q2.set(2, 14);
    q2.print();

    //isEmpty test
    std::cout << q.isEmpty() << '\n';
    std::cout << q2.isEmpty() << '\n';


    



}