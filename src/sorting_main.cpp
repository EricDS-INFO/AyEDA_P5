#include <iostream>
#include "../include/vector_t.hpp"
#include "../include/dni.hpp"
#include "../include/bubble_sorting.hpp"
#include "../include/heap_sorting.hpp"
#include "../include/insertion_sorting.hpp"
#include "../include/quick_sorting.hpp"
#include "../include/shell_sorting.hpp"


void simulate(int method, Vector_T<dni>& keys);
void stats(Vector_T<dni>& keys);
void initialize(Vector_T<dni>& keys);

int main(void) 
{   
    Vector_T<dni> keys_(10, 1);
    initialize(keys_);

    std::cout << keys_ << std::endl;
    bubble_sort(keys_, keys_.size());
    std::cout << keys_ << std::endl;
    return 0;
}


void simulate(int method, Vector_T<dni> keys)
{

}

void stats(Vector_T<dni> keys)
{

}

void initialize(Vector_T<dni>& keys)
{

    
    for(int i = keys.start(); i <= keys.end(); i++)
    {
        dni aux;
        std::cout << aux << std::endl;
        keys[i] = aux; 
    }
}