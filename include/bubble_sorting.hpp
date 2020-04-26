#pragma once
#include "vector_t.hpp"
#include <iomanip>

template <class KEY>
void bubble_sort(Vector_T<KEY>& keys, int size, bool trace = false)
{   bool modified;
    if (trace)
    {
        KEY comp, actual;
    }

    do
    {    
        modified = false;
        for (int j = keys.start(); j <= keys.end() - 1; ++j)
        {
                
            if (keys[j] > keys[j + 1])
            {
                if (trace)
                {
                    std::cout << "\n\n\033[1;31m";
                    std::cout << "Más alto: " << keys[j] << "\n";
                    std::cout << "\033[1;0m";
                    
                    std::cout << "\033[1;36m";
                    std::cout << "Intercambiado: " << keys[j + 1] << "\n\n\n";
                    std::cout << "\033[1;0m";
                    for (int i = keys.start(); i <= keys.end(); i++)
                    {
                        if (keys[j] == keys[i])
                            std::cout << "\033[1;31m";

                        if (keys[j+1] == keys[i])
                            std::cout << "\033[1;36m";
                        if (i < j)
                            std::cout << "\033[1;32m";
                        
                        std::cout <<  " | " <<  keys[i];
                        std::cout << "\033[1;0m";
                    }
                    std::cout <<  " |\n";
                    int c;
                    c=getchar();
                }        
                KEY aux = keys[j];
                keys[j] = keys[j + 1];
                keys[j + 1] = aux;
                modified = true;
            }

        }
        if (trace)
        {
            std::cout << "\nSiguiente vuelta\n";
        }        
    }while (modified);
    
}