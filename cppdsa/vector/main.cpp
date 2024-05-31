#include <iostream>
#include "list.hpp"

int main() {
    List<std::string> vect;

    List<int> vect3;

    //add test 2.0
    vect3.push(0, 1);
    vect3.push(1, 2);
    vect3.push(2, 3);
    vect3.push(3, 4);
    vect3.push(4, 5);
    vect3.push(5, 6);
    vect3.print();

    // //add test
    // vect.push(0, "1");
    // vect.push(1, "2");
    // vect.push(2, "3");
    // vect.push(3, "4" );
    // vect.push(4, "volcano");
    // vect.push(5, "and");
    // vect.push(6, "I");
    // vect.push(7, "love");
    // vect.push(8, "lava");
    // vect.push(9, "cakes");
    // vect.print();
    // vect.push(0, "Hello,");
    // vect.print();

    //operator= test
    // List<std::string> vect2;
    // vect2 = vect;

    // vect2.print();

    // //get test
    // std::cout << vect.get(0) << '\n';
    // std::cout << vect.get(5) << '\n';
    // std::cout << vect.get(10) << '\n';
    // vect.get(12);
    // vect.get(-1);

    // //set test
    // vect.set(10, "cakes!");
    // vect.set(4, "cannibalistic");
    // vect.set(5, "zebra");
    // vect.set(9, "zebra");
    // vect.print();
    // // vect.set(11, "fisherrr!");

    // //indexOf test
    // std::cout << vect.indexOf("Hello,") << '\n';
    // std::cout << vect.indexOf("zebra") << '\n';
    // std::cout << vect.indexOf("cakes!") << '\n';
    // std::cout << vect.indexOf("lava") << '\n';

    // //remove test
    // vect.remove(0);
    // vect.print();
    // vect.remove(5);
    // vect.print();
    // vect.remove(vect.length() - 1);
    // vect.print();
    // // vect.remove(11);

    // //clear test
    // std::cout << vect2.length() << '\n';
    // vect2.clear();
    // std::cout << vect2.length() << '\n';

    // //reverse test
    // vect.reverse();
    // vect.print();

    // // rotate test
    // vect3.rotate(2);
    // vect3.print();

    //removeRange test
    // vect3.removeRange(2, 3);
    // vect3.print();

    // //shrink test
    // vect3.remove(5);
    // vect3.remove(4);
    // vect3.shrink();
    // std::cout << "SIZE: " << vect3.getMax() << '\n';

    //subArray test
    vect3.subArray(3, 5);
    vect3.print();
}