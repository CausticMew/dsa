#include <iostream>
#include "list.hpp"

int main() {
    List <int> l;
    List <int> l2;

    //push test
    l.push(7);
    l.push(11);
    l.push(13);

    // //print test
    // l.print();

    // //search test
    // l.search(12);
    // l.search(11);

    // //addAt test 
    // l.addAt(1, 12);
    // l.print();

    //remove test
    // l.remove(1);
    // l.print();
    // l.remove(0);
    // l.print();
    // l.remove(l.length() - 1);
    // l.print();
    // l.remove(4);
    // l.print();

    //set test
    l.set(1, 5);
    l.print();
    l.set(0, 4);
    l.print();
    l.set(2, 6);
    l.print();
    l.set(7, 8);
    // l2.set(0, 15);
    // l2.print();

    //get test
    std::cout << "Index 0: " << l.get(0) << '\n';
    std::cout << "Index 1: " << l.get(1) << '\n';
    std::cout << "Index 2: " << l.get(2) << '\n';
    std::cout << "Index 0: " << l2.get(0) << '\n';
    

}