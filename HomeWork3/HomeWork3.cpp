#include <iostream>

int main() {
    unsigned int sum{ 0 };
    const int codenum = 5312;
    unsigned int x = 0;
    int input = 0;
    
    do {
        std::cin >> input;
        if (input < 0) {
            std::cout << "некорректный формат ввода"<< std::endl;
        }
        else if (!std::cin || std::cin.peek() != '\n')
        {
            std::cout << "некорректный формат ввода"<< std::endl;
            std::cin.clear();
            std::cin.ignore(100500, '\n');
        }
        else {
            x = input;
            if (x != 5312) {
                sum += x;
            }
        }

    } while (x != 5312);
    std::cout << sum;
}