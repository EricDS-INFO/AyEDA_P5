#include <iostream>
#include "../include/vector_t.hpp"

int main(void) 
{
    Vector_T<int> myvector(5, 2);

    std::cout << myvector.size() << "\n";
    std::cout << myvector.start() << "\n";
    std::cout << myvector.end() << "\n";
    std::cout <<  myvector << "\n";
    myvector.push_back(4);

    std::cout <<  myvector << "\n";
    std::cout << myvector.size() << "\n";
    std::cout << myvector.start() << "\n";
    std::cout << myvector.end() << "\n";
    
    std::cout <<  myvector << "\n";


    return 0;
}