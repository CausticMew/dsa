#include <iostream>
#include "stack.hpp"

int main() {
   Stack <int> s; 
   Stack <int> s2;

   //push test
   s.push(7);
   s.push(11);
   s.push(13);

   //copy constructor test
   Stack s3(s);
   s3.print();

   //destructor test
   s3.~Stack();
   s3.print();

    //print test
    s.print();

    //pop test
    s.pop();
    s.print();

    //peak test
    std::cout << "Peak Test: " << s.peak() << '\n';

    //get test
    std::cout << "Get Test: " << s.get(1) << '\n';

    //set test
    s.set(0, 3);
    s.print();

    //isEmpty test
    std::cout << std::boolalpha << "isEmpty Test: " << s.isEmpty() << '\n';
    std::cout << "isEmpty Test: " << s2.isEmpty() << '\n';

    //length test
    std::cout << "Length Test: " << s.length() << '\n';

    //operator= test
    s2 = s;
    std::cout << "main test\n";
    s2.print();
    std::cout << "main test2\n";

    //clear test
    s2.clear();
    std::cout << "main test3\n";
    std::cout << "Clear Test: " << s.isEmpty() << '\n';

    std::cout << "s1: " << &s << ' ';
    s.address();
    std::cout << "s2: " << &s2 << ' ';
    s2.address();
    std::cout << "s3: " << &s3 << ' ';
    s3.address();


    
}