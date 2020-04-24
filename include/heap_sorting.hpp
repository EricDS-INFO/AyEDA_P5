#pragma once
#include "vector_t.hpp"
#include <iostream>

template <class KEY>
void heapify( Vector_T<KEY>& keys,  int sz, int pos ) {
    while ( 2 * pos <= sz ){
        int largest;
        int left = 2 * pos;
        int right = left + 1;
        if (left == sz)
            largest  = left;
        else 
            if (keys[left] > keys[right])
                largest  = left;
            else 
                largest = right ;
        if (keys[largest] <= keys[pos])
            break ;
        else {
            std::swap(keys[pos], keys[largest]) ;
            pos = largest ;
        } ;
    } ;
} 

template <class KEY>
void heap_sort(Vector_T<KEY>& keys, int size)
{
    for(int i = size/2; i > 0; i-- )

        heapify(keys, size, i);

    for(int i = size ; i > 1; i--)
    {
        std::swap(keys[1], keys[i]);
        std::cout << keys[1] <<"\n";
        heapify(keys, i-1, 1);
    } 
}




template <class KEY>
void swap(KEY& prev,  KEY& next)
{
    KEY aux = prev;
    prev = next;
    next = aux;
}