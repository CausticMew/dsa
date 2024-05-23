#include <iostream>
#include "list.hpp"

int main() {
    std::cout << "Hello World!\n";

    List<std::string> vect;

//add test
    vect.push("I", 0);
    vect.push("am", 1);
    vect.push("a", 2);
    vect.push("dormant", 3);
    vect.push("volcano", 4);
    vect.push("and", 5);
    vect.push("I", 6);
    vect.push("love", 7);
    vect.push("lava", 8);
    vect.push("cakes", 9);
    vect.print();
    vect.push("Hello,", 0);
    vect.print();
}