#pragma once
#include "vector_t.hpp"
#include <iostream>

template <class KEY>
void heapify( Vector_T<KEY>& keys,  int sz, int pos, bool simulate = false ) {
    int reg = pos;
    int left; 
    int right;
    int largest;
    while ( 2 * pos <= sz )
    {
        

        left = 2 * pos;
        right = left + 1;
        if (left == sz)
            largest  = left;
        else 
            if (keys[left] > keys[right])
                largest  = left;
            else 
                largest = right ;
        if (keys[largest] <= keys[pos])
            break ;
        else 
        {
            std::swap(keys[pos], keys[largest]) ;
            pos = largest ;
        }

    }

        if (simulate)
        {
            for  (int j = keys.start(); j <= keys.end(); j++)
            {
                if(j == sz || j == reg)
                    std::cout << "\033[1;31m";
                if((j > reg && j < sz))
                    std::cout << "\033[1;36m";
                if(j == largest)
                    std::cout << "\033[1;32m";
                std::cout <<"| [" << j << "]" <<keys[j];
                std::cout << "\033[1;0m";
            }
            std::cout << "|";
            
            int c;
            getchar();
        }

} 

template <class KEY>
void heap_sort(Vector_T<KEY>& keys, int size, bool simulate = false)
{
    if (simulate)
    {
        std::cout << "\nINSERCIONES\n";
    }
    for(int i = size/2; i > 0; i-- )
    {
        heapify(keys, size, i, simulate);

    }

    if (simulate)
    {
        std::cout << "\nEXTRACCIONES\n";
    }
    for(int i = size ; i > 1; i--)
    {
        std::swap(keys[1], keys[i]);
        heapify(keys, i-1, 1, simulate);
    } 

}




template <class KEY>
void swap(KEY& prev,  KEY& next)
{
    KEY aux = prev;
    prev = next;
    next = aux;
}