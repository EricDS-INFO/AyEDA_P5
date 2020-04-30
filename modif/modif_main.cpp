#include <iostream>

#include "../include/insertion_sorting.hpp"
#include "../include/selection_sorting.hpp"
#include "../include/bubble_sorting.hpp"
#include "../include/quick_sorting.hpp"
#include "../include/heap_sorting.hpp"
#include "../include/shell_sorting.hpp"

#include "../include/vector_t.hpp"

#include "ISBN.hpp"

void initialize(Vector_T<isbn>& keys, bool preseed = false);


int main (void)
{
    Vector_T<isbn> books(10,1);

    std::cout << "\t\t\t\t\t\t\t\t  PROGRAMA DE COMPROBACIÓN DE ORDENACIÓN CON CLAVES ISBN\n";
    
    initialize(books);
    std::cout << "\n\n\nMétodo de inserción: \n\nAntes:\n" << books;
    insertion_sort(books, books.size());
    std::cout << "\nDespués:\n" << books;

    
    initialize(books);
    std::cout << "\n\n\nMétodo de selección: \n\nAntes:\n" << books;
    selection_sort(books, books.size());
    std::cout << "\nDespués:\n" << books;

    initialize(books);
    std::cout << "\n\n\nMétodo de la burbuja: \n\nAntes:\n" << books;
    bubble_sort(books, books.size());
    std::cout << "\nDespués:\n" << books;

    initialize(books);
    std::cout << "\n\n\nMétodo Quick sort: \n\nAntes:\n" << books;
    quick_sort(books, books.start(), books.end());
    std::cout << "\nDespués:\n" << books;

    initialize(books);
    std::cout << "\n\n\nMétodo Heap Sort: \n\nAntes:\n" << books;
    heap_sort(books, books.size());
    std::cout << "\nDespués:\n" << books;

    initialize(books);
    std::cout << "\n\n\nMétodo Shell Sort: \n\nAntes:\n" << books;
    shell_sort(books, books.size());
    std::cout << "\nDespués:\n" << books;

}


void initialize(Vector_T<isbn>& keys, bool preseed )
{
    
    for(int i = keys.start(); i <= keys.end(); i++)
    {
        if (preseed)
            srand(i);   
        isbn aux;
        keys[i] = aux; 
    }
}