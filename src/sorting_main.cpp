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

int main(int argc, char* argv[]) 
{   
    
    Vector_T<dni> keys_(10, 1);
    

    srand(time(NULL));    
    initialize(keys_);


    simulate(3, keys_);

    return 0;
}


void simulate(int method, Vector_T<dni>& keys)
{

        switch (method)
        {
        case 1:
            insertion_sort<dni>(keys, keys.size(), true);
            break;
        case 2:
            bubble_sort<dni>(keys, keys.size(), true);
            break;
        case 3:
            quick_sort<dni>(keys, keys.start(),keys.end(), true);
            break;
        case 4:
            heap_sort<dni>(keys, keys.size());
            
            break;
        case 5:
            shell_sort<dni>(keys, keys.size());
            
            break;
        
        default:
            break;
        }
    
}

void stats(Vector_T<dni> keys)
{

}

void initialize(Vector_T<dni>& keys)
{
    
    for(int i = keys.start(); i <= keys.end(); i++)
    {
        dni aux;
        keys[i] = aux; 
    }
}