#pragma once
#include "./vector_t.hpp"

template <class KEY> 
void insertion_sort (Vector_T<KEY>& keys, int size, bool simulate = false)
{
    for (int i = keys.start() + 1; i <= keys.end(); i++)
    {
        int pos = i;
        KEY value = keys[i];
        
        if (simulate)
        {
            std::cout << " \n\n";
        }

        while ((pos > keys.start()) && (value < keys[pos -1]))
        {
            

            keys[pos] = keys[pos -1];
            if (simulate)
            {
                for (int j = keys.start(); j <= keys.end(); j++ )
                {
                    if (keys[j] == keys[pos])
                    {
                        std::cout << "\033[1;31m";   
                        std::cout << "<-[" << j << "] " << value;     
                    }
                    else
                    {
                        std::cout << "| [" << j << "] " << keys[j];    
                    }
                    
                    std::cout << "\033[1;0m";
                }
                    std::cout << " |\n";
            }
            pos--;
        }

        if (simulate)
        {
            std::cout << " \n\n";
        }
        keys[pos] = value;
        if (simulate)
        {
            for (int k = keys.start(); k <= keys.end(); k++ )
            {
                if (keys[pos + 1] == keys[k])
                    std::cout << "\033[1;31m";
                if (pos  >= k)
                {
                    std::cout << "\033[1;0m";
                    std::cout << "\033[1;32m";
                }
                std::cout << "| [" << k << "] " << keys[k];
                    std::cout << "\033[1;0m";
            }

            std::cout << " |\n";
            std::cout << "\n----------------Siguiente vuelta----------------\n";
            int c;
            c=getchar();
        }

    }
    
};

