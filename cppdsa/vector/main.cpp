#include <iostream>
#include "list.hpp"

int main() {
    std::cout << "Hello World!\n";

    List<std::string> vect;

    //add test
    vect.push(0, "I");
    vect.push(1, "am");
    vect.push(2, "a");
    vect.push(3, "dormant" );
    vect.push(4, "volcano");
    vect.push(5, "and");
    vect.push(6, "I");
    vect.push(7, "love");
    vect.push(8, "lava");
    vect.push(9, "cakes");
    vect.print();
    vect.push(0, "Hello,");
    vect.print();

    //get test
    std::cout << vect.get(0) << '\n';
    std::cout << vect.get(5) << '\n';
    std::cout << vect.get(10) << '\n';
    // vect.get(12);
    // vect.get(-1);

    //set test
    vect.set(10, "cakes!");
    vect.set(4, "cannibalistic");
    vect.set(5, "zebra");
    vect.set(9, "zebra");
    vect.print();
    vect.set(11, "fisherrr!");


}