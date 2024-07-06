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
    l.print();

    // //search test
    // l.search(12);
    // l.search(11);

    // //addAt test 
    l.addAt(1, 12);
    l.print();
    l.printReverse();

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
    // l.set(1, 5);
    // l.print();
    // l.set(0, 4);
    // l.print();
    // l.set(2, 6);
    // l.print();
    // l.set(7, 8);
    // l2.set(0, 15);
    // l2.print();

    //get test
    // std::cout << "Index 0: " << l.get(0) << '\n';
    // std::cout << "Index 1: " << l.get(1) << '\n';
    // std::cout << "Index 2: " << l.get(2) << '\n';
    // std::cout << "Index 0: " << l2.get(0) << '\n';

    //copy constructor test
    // List <int> l3(l);
    // l3.print();
    // l3.printReverse();
    // std::cout << "Size of L3: " << l3.length() << '\n';
    // List <int> l4(l2);
    // l4.print();

    //copy mimic2 test
    // List <int> l3(l);
    // l3.print();
    // std::cout << "Size of L3: " << l3.length() << '\n';
    // List <int> l4(l2);
    // l4.print();

    //destroy mimic test
    // l.destroy();
    // l.print(); 
    // std::cout << std::boolalpha << l.isEmpty() <<'\n';

    //destroy mimic2 test
    // l.destroy2();
    // l.print(); 
    // std::cout << std::boolalpha << l.isEmpty() <<'\n';

    //destructor test
    // l.~List();
    // l.print(); 
    // std::cout << std::boolalpha << l.isEmpty() <<'\n';

    //indexOf test
    // l.indexOf(8);
    // l.indexOf(5);

    //indexesOf test
    // l.set(0, 5);
    // l.indexesOf(5);
    // l.set(2, 5);
    // l.indexesOf(5);
    // l2.indexesOf(9);

    //printReverse test
    // l.printReverse();
}