#include <iostream>

int main() {
    int int1 = 3, int2 = 5;
    char char1 = 'a', char2 = 'b';
    double double1 = 5.5, double2 = 6.3;

    std::cout <<"int+int = " << int1 + int2 << "\n";
    std::cout <<"int+char = " << int1 + char1 << "\n";
    std::cout <<"char+char = " << char1 + char2 << "\n";
    std::cout <<"double+double = " << double1 + double2 << "\n";
    std::cout <<"double+char = " << double1 + char1 << "\n";
    std::cout <<"double+int = " << double1 + int1 << "\n";
}