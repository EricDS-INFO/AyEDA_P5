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

    int sz_ = 0, init = 0, method = 0;
    std::cout << "Indique un tamaño para el vector: ";
    std::cin >> sz_; 

    std::cout << "y el índice inicial del vector: ";
    std::cin >> init; 
    Vector_T<dni> keys_(sz_, init);
    
    srand(time(NULL));    
    initialize(keys_);

    std::cout << "\tElija un método para simular: \n";
    std::cout << "\t1 -> Ordenación por inserción\n";
    std::cout << "\t2 -> Ordenación burbuja\n";
    std::cout << "\t3 -> Ordenación Quick\n";
    std::cout << "\t4 -> Ordenación Heap\n";
    std::cout << "\t5 -> Ordenación Shell\n";
    std::cin >> method;

    simulate(method, keys_);

    return 0;
}


void simulate(int method, Vector_T<dni>& keys)
{

        switch (method)
        {
        case 1:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN POR INSERCIÓN\n";
            insertion_sort<dni>(keys, keys.size(), true);
            break;
        case 2:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN BURBUJA\n";
            bubble_sort<dni>(keys, keys.size(), true);
            break;
        case 3:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN QUICK\n";
            quick_sort<dni>(keys, keys.start(),keys.end(), true);
            break;
        case 4:
            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN HEAP\n";
            heap_sort<dni>(keys, keys.size(), true);
            break;
        case 5:

            std::cout << "\t\t\t\t\tSIMULACIÓN DE ORDENACIÓN SHELL\n";
            shell_sort<dni>(keys, keys.size(), true);    
            break;
        default:
            std::cout << "\t\t\t\t\tERROR: no existe el método indicado\n";
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