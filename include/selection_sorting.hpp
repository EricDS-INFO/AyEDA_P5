#pragma once
#include "./vector_t.hpp"

template <class KEY> 
void selection_sort (Vector_T<KEY>& keys, int size, bool simulate = false)
{
    for (int i = keys.start(); i < keys.end(); i++)
    {
        int min = i;
        for (size_t j = i + 1; j <= keys.end(); j++)
            if (keys[j] < keys[min])
                min = j;
        
        
        if (simulate)
        {
            for (int j = keys.start(); j <= keys.end(); j++)
            {
                if (keys[j] < keys[min])
                    std::cout << "\033[1;32m";

                if (keys[j] == keys[min])
                    std::cout << "\033[1;36m";
                std::cout << "| ["<< j <<"]" << keys[j];
                std::cout << "\033[1;0m";
            }
            std::cout << "|";
            getchar();
        }
        std::swap(keys[min], keys[i]);
        
    }
}
